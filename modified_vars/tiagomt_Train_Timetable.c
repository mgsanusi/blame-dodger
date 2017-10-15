#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Viag
{
  int a;
  int in;
  int x;
} Viag;
Viag r[2][128];
int n[2];
int viagcmp1(const void *b, const void *e2)
{
  Viag *ein;
  Viag *v2;
  ein = (Viag *) b;
  v2 = (Viag *) e2;
  return ein->a - v2->a;
}

int viagcmp2(const void *b, const void *e2)
{
  Viag *ein;
  Viag *v2;
  ein = (Viag *) b;
  v2 = (Viag *) e2;
  return ein->in - v2->in;
}

int Main(void)
{
  int cs;
  int h;
  int ans;
  int s1;
  int s2;
  int f1;
  int len;
  int cnt[2];
  int order;
  int d;
  int x;
  int l;
  for (scanf("%d", &cs), h = 1; h <= cs; h++)
  {
    scanf("%d", &ans);
    scanf("%d%d", &n[0], &n[1]);
    for (order = 0; order < 2; order++)
    {
      for (d = 0; d < n[order]; d++)
      {
        scanf("%d:%d %d:%d", &s1, &s2, &f1, &len);
        r[order][d].a = (s1 * 60) + s2;
        r[order][d].in = (f1 * 60) + len;
      }

    }

    for (order = 0; order < 2; order++)
    {
      d = 1 - order;
      qsort(r[order], n[order], sizeof(r[order][0]), viagcmp1);
      qsort(r[d], n[d], sizeof(r[d][0]), viagcmp2);
      for (x = 0; x < n[d]; x++)
      {
        r[d][x].x = 0;
      }

      cnt[order] = 0;
      for (x = 0; x < n[order]; x++)
      {
        for (l = 0; l < n[d]; l++)
        {
          if ((r[d][l].in + ans) > r[order][x].a)
          {
            l = n[d];
            break;
          }

          if (!r[d][l].x)
          {
            break;
          }

        }

        if (l < n[d])
        {
          r[d][l].x = 1;
        }
        else
        {
          cnt[order]++;
        }

      }

    }

    printf("Case #%d: %d %d\n", h, cnt[0], cnt[1]);
  }

  return 0;
}


