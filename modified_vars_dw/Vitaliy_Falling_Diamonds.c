#include <stdio.h>
#include <assert.h>
#include <string.h>
int r[1000];
double r[10001][10001];
double q[10000];
void clear(void)
{
  int first_iteration;
  int n;
  int b;
  int y;
  scanf("%d%d%d", &n, &b, &y);
  if (b < 0)
  {
    b = -b;
  }

  int level = (b + y) / 2;
  int cnt = level + (2 * (level * (level - 1)));
  if (cnt >= n)
  {
    printf("0\n");
    return;
  }

  int t = n - cnt;
  if (t >= (((2 * level) + y) + 1))
  {
    printf("1\n");
    return;
  }

  if (t <= y)
  {
    printf("0\n");
    return;
  }

  if (y == (2 * level))
  {
    printf("0\n");
    return;
  }

  double m = 0;
  int nLen;
  for (nLen = 0; nLen <= y; nLen++)
  {
    m += r[t][nLen];
  }

  printf("%lf\n", 1 - m);
}

int Main()
{
  int first_iteration;
  int nLen;
  int dp;
  r[0][0] = 1;
  for (nLen = 1; nLen <= 10000; nLen++)
  {
    r[nLen][nLen] = r[nLen - 1][nLen - 1] / 2;
    for (dp = 0; dp <= nLen; dp++)
    {
      r[nLen][dp] = (r[nLen - 1][dp] + r[nLen - 1][dp - 1]) / 2;
    }

  }

  int ok;
  assert(scanf("%d\n", &ok) > 0);
  int ans;
  for (ans = 0; ans < ok; ans++)
  {
    printf("Case #%d: ", ans + 1);
    clear();
  }

  return 0;
}


