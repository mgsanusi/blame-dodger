#include<stdio.h>
#include<string.h>
int a1[128];
int a2[128];
long long b1[128];
long long b2[128];
long long dp[128][128];
int n;
int m;
int main()
{
  int first_iteration;
  int N;
  int cs = 0;
  int i;
  int j;
  int k;
  int l;
  long long ret;
  long long t1;
  long long t2;
  long long t;
  for (scanf("%d", &N); N--;)
  {
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
      scanf("%lld %d", &b1[i], &a1[i]);

    for (i = 0; i < m; i++)
      scanf("%lld %d", &b2[i], &a2[i]);

    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
    {
      if (dp[i][j] > dp[i + 1][j])
        dp[i + 1][j] = dp[i][j];

      if (dp[i][j] > dp[i][j + 1])
        dp[i][j + 1] = dp[i][j];

      t1 = (t2 = 0);
      t = dp[i][j];
      for (k = i, l = j; ((k < n) || t1) && ((l < m) || t2);)
      {
        for (; (!t1) && (k < n); k++)
          if (a1[k] == a1[i])
          t1 += b1[k];


        for (; (!t2) && (l < m); l++)
          if (a2[l] == a1[i])
          t2 += b2[l];


        if (t1 > t2)
        {
          t += t2, t1 -= t2, t2 = 0;
          if (t > dp[k][l])
            dp[k][l] = t;

        }
        else
        {
          t += t1, t2 -= t1, t1 = 0;
          if (t > dp[k][l])
            dp[k][l] = t;

        }

      }

      t1 = (t2 = 0), t = dp[i][j];
      for (k = i, l = j; ((k < n) || t1) && ((l < m) || t2);)
      {
        for (; (!t1) && (k < n); k++)
          if (a1[k] == a2[j])
          t1 += b1[k];


        for (; (!t2) && (l < m); l++)
          if (a2[l] == a2[j])
          t2 += b2[l];


        if (t1 > t2)
        {
          t += t2, t1 -= t2, t2 = 0;
          if (t > dp[k][l])
            dp[k][l] = t;

        }
        else
        {
          t += t1, t2 -= t1, t1 = 0;
          if (t > dp[k][l])
            dp[k][l] = t;

        }

      }

    }


    ret = 0;
    for (i = 0; i <= n; i++)
      for (j = 0; j <= m; j++)
      if (dp[i][j] > ret)
      ret = dp[i][j];



    printf("Case #%d: %lld\n", ++cs, ret);
  }

  return 0;
}


