#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
  int t;
  int p[128][2];
} Cust;
Cust cust[128];
int m;
int mrc[16];
int n;
int r;
int res[16];
void bt(int s, int p)
{
  int first_iteration;
  int i;
  int j;
  if (p == n)
  {
    if (s >= r)
    {
      return;
    }

    for (i = 0; i < m; i++)
    {
      for (j = 0; j < cust[i].t; j++)
      {
        if (mrc[cust[i].p[j][0]] == cust[i].p[j][1])
        {
          break;
        }

      }

      if (j == cust[i].t)
      {
        break;
      }

    }

    if (i < m)
    {
      return;
    }

    r = s;
    for (i = 0; i < n; i++)
    {
      res[i] = mrc[i];
    }

    return;
  }

  mrc[p] = 0;
  bt(s, p + 1);
  mrc[p] = 1;
  bt(s + 1, p + 1);
}

int main(void)
{
  int first_iteration;
  int nc;
  int h;
  int i;
  int j;
  for (scanf("%d", &nc), h = 1; h <= nc; h++)
  {
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
      scanf("%d", &cust[i].t);
      for (j = 0; j < cust[i].t; j++)
      {
        scanf("%d%d", &cust[i].p[j][0], &cust[i].p[j][1]);
        cust[i].p[j][0]--;
      }

    }

    printf("Case #%d:", h);
    memset(mrc, 0, sizeof(mrc));
    r = 0x3F3F3F3F;
    bt(0, 0);
    if (r < 0x3F3F3F3F)
    {
      for (i = 0; i < n; i++)
      {
        printf(" %d", res[i]);
      }

      printf("\n");
    }
    else
    {
      printf(" IMPOSSIBLE\n");
    }

  }

  return 0;
}


