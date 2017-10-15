#include <stdio.h>
#include <stdlib.h>
int Main()
{
  int trial;
  int testc;
  int p;
  int q;
  int s;
  int m;
  int n;
  int xp_freeargs;
  int res;
  freopen("gcj1_2.in", "r", stdin);
  freopen("gcj1_2.out", "w", stdout);
  scanf("%d\n", &testc);
  for (trial = 1; trial <= testc; trial++)
  {
    scanf("%d%d%d", &s, &m, &n);
    p = (3 * n) - 2;
    q = (3 * n) - 4;
    res = 0;
    for (; s; s--)
    {
      scanf("%d", &xp_freeargs);
      if (xp_freeargs < 2)
      {
        if (xp_freeargs >= n)
          res++;

      }
      else
      {
        if (xp_freeargs >= p)
          res++;
        else
          if ((xp_freeargs >= q) && m)
        {
          res++;
          m--;
        }


      }

    }

    printf("Case #%d: %d\n", trial, res);
  }

  return 0;
}


