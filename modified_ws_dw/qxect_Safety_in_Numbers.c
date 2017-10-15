#include<stdio.h>
#include<string.h>
int map[1010][1010];
int dp[1010][1010];
int main()
{
  int first_iteration;
  int tn;
  int n;
  int i;
  int j;
  int k;
  int l;
  int t;
  int m;
  int p;
  int q;
  int now;
  int ans;
  scanf("%d", &tn);
  for (l = 1; l <= tn; l++)
  {
    memset(map, 0, sizeof(map));
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
      scanf("%d", &m);
      while (m--)
      {
        scanf("%d", &t);
        map[i][t]++;
      }

    }

    ans = 0;
    for (k = 1; (k <= n) && (ans == 0); k++)
    {
      memcpy(dp, map, sizeof(dp));
      for (i = 1; (i <= n) && (ans == 0); i++)
      {
        for (j = 1; (j <= n) && (ans == 0); j++)
        {
          dp[i][j] += map[i][k] * map[k][j];
          if (dp[i][j] > 1)
            ans = 1;

        }

      }

      memcpy(map, dp, sizeof(dp));
    }

    printf("Case #%d: ", l);
    if (ans)
      printf("Yes\n");
    else
      printf("No\n");

  }

  return 0;
}


