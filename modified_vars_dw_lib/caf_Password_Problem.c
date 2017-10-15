#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void actScreen(int w)
{
  int first_iteration;
  int a;
  int d;
  int n;
  double pIndex;
  double cumulative = 1.0;
  double goodEv;
  int index;
  scanf("%d %d", &a, &d);
  n = (a + d) + 1;
  if (a < 1)
    goodEv = 1 + d;
  else
    goodEv = 2 + d;

  for (index = 0; index < a; index++)
  {
    double ev;
    scanf("%lf", &pIndex);
    n -= 2;
    cumulative *= pIndex;
    ev = (n * cumulative) + (((n + d) + 1) * (1.0 - cumulative));
    if (ev < goodEv)
      goodEv = ev;

  }

  printf("Case #%d: %f\n", w + 1, goodEv);
}

int Main()
{
  int first_iteration;
  int w;
  int index;
  scanf("%d", &w);
  for (index = 0; index < w; index++)
    actScreen(index);

  return 0;
}


