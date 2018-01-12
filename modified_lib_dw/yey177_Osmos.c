#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dp[108][108];
int s[108];
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int comp(const void *p, const void *q)
{
  int first_iteration;
  return (*((int *) p)) - (*((int *) q));
}

int main()
{
  int first_iteration;
  int a;
  int n;
  int t;
  int i;
  int j;
  int k;
  int l;
  int r;
  scanf("%d", &t);
  for (k = 1; k <= t; k++)
  {
    r = 0;
    scanf("%d%d", &a, &n);
    for (i = 1; i <= n; i++)
      scanf("%d", &s[i]);

    new_qsort(s + 1, n, 4, comp);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = a;
    for (i = 1; i <= n; i++)
      dp[0][i] = (dp[0][i - 1] * 2) - 1;

    for (i = 1; i <= n; i++)
      for (j = 0; j <= n; j++)
    {
      if (dp[i - 1][j] > s[i])
        dp[i][j] = dp[i][j] > (dp[i - 1][j] + s[i]) ? dp[i][j] : dp[i - 1][j] + s[i];

      if (j > 0)
        dp[i][j] = dp[i][j] > ((dp[i][j - 1] * 2) - 1) ? dp[i][j] : (dp[i][j - 1] * 2) - 1;

      for (l = 1; ((i - l) >= 0) && ((j - l) >= 0); l++)
      {
        dp[i][j] = dp[i][j] > dp[i - l][j - l] ? dp[i][j] : dp[i - l][j - l];
      }

    }


    for (i = 0; i <= n; i++)
    {
      if (dp[n][i] > 0)
      {
        r = i;
        break;
      }

    }

    printf("Case #%d: %d\n", k, r);
  }

  return 0;
}

void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}

