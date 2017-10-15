#include <stdio.h>
#include <string.h>
int d[10008];
int l[10008];
int dp[10008];
int main()
{
  int first_iteration;
  int t;
  int k;
  int n;
  int D;
  int res = 0;
  int tmp;
  int i;
  int j;
  scanf("%d", &t);
  for (k = 1; k <= t; k++)
  {
    res = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%d%d", &d[i], &l[i]);
    }

    scanf("%d", &D);
    memset(dp, -1, sizeof(dp));
    dp[0] = d[0] * 2;
    for (i = 0; i < n; i++)
    {
      if (dp[i] >= D)
      {
        res = 1;
        break;
      }

      j = i + 1;
      while ((j < n) && (d[j] <= dp[i]))
      {
        tmp = l[j] < (d[j] - d[i]) ? l[j] : d[j] - d[i];
        dp[j] = dp[j] > (d[j] + tmp) ? dp[j] : d[j] + tmp;
        j++;
      }

    }

    printf("Case #%d: %s\n", k, res ? "YES" : "NO");
  }

  return 0;
}


