#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void makeTest(int e)
{
  int l;
  int k;
  int q;
  double pI;
  double cumulative = 1.0;
  double fullEv;
  int i;
  scanf("%d %d", &l, &k);
  q = (l + k) + 1;
  if (l < 1)
    fullEv = 1 + k;
  else
    fullEv = 2 + k;

  for (i = 0; i < l; i++)
  {
    double ev;
    scanf("%lf", &pI);
    q -= 2;
    cumulative *= pI;
    ev = (q * cumulative) + (((q + k) + 1) * (1.0 - cumulative));
    if (ev < fullEv)
      fullEv = ev;

  }

  printf("Case #%d: %f\n", e + 1, fullEv);
}

int Main()
{
  int e;
  int i;
  scanf("%d", &e);
  for (i = 0; i < e; i++)
    makeTest(i);

  return 0;
}


