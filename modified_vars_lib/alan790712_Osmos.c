#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int new_abs(int x);

int new_abs(int a)
{
  if (a < 0)
    return -a;

  return a;
}

int k;
int k;
int p2;
int dp[123456] = {0, 1};
int s;
double result;
void dfs(int now, int k, int zBuf2, int k, int p2, int b, int b, double tt)
{
  if (now >= k)
  {
    if ((k < 0) && (b > p2))
    {
      result += tt;
    }

    if ((k > 0) && (b > p2))
    {
      result += tt;
    }

    return;
  }

  if (b == zBuf2)
  {
    dfs(now + 1, k, zBuf2, k, p2, b, b + 1, tt);
  }
  else
    if (b == zBuf2)
  {
    dfs(now + 1, k, zBuf2, k, p2, b + 1, b, tt);
  }
  else
  {
    dfs(now + 1, k, zBuf2, k, p2, b + 1, b, tt / 2.0);
    dfs(now + 1, k, zBuf2, k, p2, b, b + 1, tt / 2.0);
  }


}

int Main()
{
  int t;
  int t;
  int res;
  int j;
  for (res = (j = 2); res < 20; ++res)
  {
    dp[res] = (dp[res - 1] + (j * 2)) + 1;
    j += 2;
  }

  scanf("%d", &t);
  for (t = 1; t <= t; ++t)
  {
    scanf("%d %d %d", &k, &k, &p2);
    s = (new_abs(k) + new_abs(p2)) / 2;
    printf("Case #%d: ", t);
    for (res = 0; dp[res + 1] <= k; ++res)
      ;

    if (res > s)
    {
      result = 1.0;
    }
    else
    {
      if (res < s)
        result = 0.0;
      else
      {
        s = k - dp[res];
        result = 0.0;
        dfs(0, s, (dp[res + 1] - dp[res]) / 2, k, p2, 0, 0, 1.0);
      }

    }

    printf("%lf\n", result);
  }

  return 0;
}



int new_abs(int x) {
  return abs(x);
}