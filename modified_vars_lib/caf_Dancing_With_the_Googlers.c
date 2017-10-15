#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void doTest(int b)
{
  int j;
  int w;
  int c;
  int v;
  int threshNorm;
  int threshSurprise;
  int k = 0;
  scanf("%d %d %d", &w, &c, &v);
  threshNorm = v > 0 ? (3 * v) - 2 : 0;
  threshSurprise = v > 1 ? (3 * v) - 4 : v;
  for (j = 0; j < w; j++)
  {
    int sum;
    scanf("%d", &sum);
    if (v > 10)
      continue;

    if (sum >= threshNorm)
    {
      k++;
    }
    else
      if ((c > 0) && (sum >= threshSurprise))
    {
      k++;
      c--;
    }


  }

  printf("Case #%d: %d\n", b + 1, k);
}

int Main()
{
  int b;
  int j;
  scanf("%d", &b);
  for (j = 0; j < b; j++)
    doTest(j);

  return 0;
}


