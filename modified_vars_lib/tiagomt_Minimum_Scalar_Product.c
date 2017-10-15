#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
  int t;
  int c[128][2];
} Cust;
Cust cust[128];
int k;
int mrc[16];
int n;
int x;
int answer[16];
void bt(int s, int c)
{
  int i;
  int root;
  if (c == n)
  {
    if (s >= x)
    {
      return;
    }

    for (i = 0; i < k; i++)
    {
      for (root = 0; root < cust[i].t; root++)
      {
        if (mrc[cust[i].c[root][0]] == cust[i].c[root][1])
        {
          break;
        }

      }

      if (root == cust[i].t)
      {
        break;
      }

    }

    if (i < k)
    {
      return;
    }

    x = s;
    for (i = 0; i < n; i++)
    {
      answer[i] = mrc[i];
    }

    return;
  }

  mrc[c] = 0;
  bt(s, c + 1);
  mrc[c] = 1;
  bt(s + 1, c + 1);
}

int Main(void)
{
  int lend;
  int h;
  int i;
  int root;
  for (scanf("%d", &lend), h = 1; h <= lend; h++)
  {
    scanf("%d%d", &n, &k);
    for (i = 0; i < k; i++)
    {
      scanf("%d", &cust[i].t);
      for (root = 0; root < cust[i].t; root++)
      {
        scanf("%d%d", &cust[i].c[root][0], &cust[i].c[root][1]);
        cust[i].c[root][0]--;
      }

    }

    printf("Case #%d:", h);
    memset(mrc, 0, sizeof(mrc));
    x = 0x3F3F3F3F;
    bt(0, 0);
    if (x < 0x3F3F3F3F)
    {
      for (i = 0; i < n; i++)
      {
        printf(" %d", answer[i]);
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


