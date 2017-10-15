#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int x;
int y;
long long dp[55][55][5];
long long now;
long long g;
long long add;
long long s[55][55];
long long w[55][55];
long long t[55][55];
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &x, &y);
    for (i = 0; i < x; i++)
      for (j = 0; j < y; j++)
      scanf("%lld%lld%lld", s[(x - 1) - i] + j, w[(x - 1) - i] + j, t[(x - 1) - i] + j);


    for (i = 0; i < x; i++)
      for (j = 0; j < y; j++)
    {
      t[i][j] = (-t[i][j]) % (s[i][j] + w[i][j]);
      if (t[i][j] < 0)
        t[i][j] += s[i][j] + w[i][j];

    }


    for (i = 0; i < x; i++)
      for (j = 0; j < y; j++)
      for (k = 0; k < 4; k++)
      dp[i][j][k] = 100000000000000000LL;



    dp[0][0][0] = 0;
    for (;;)
    {
      int fg = 0;
      for (i = 0; i < x; i++)
        for (j = 0; j < y; j++)
      {
        k = 0;
        now = dp[i][j][k];
        if (i && (dp[i - 1][j][2] > (now + 2)))
          dp[i - 1][j][2] = now + 2, fg++;

        if (j && (dp[i][j - 1][1] > (now + 2)))
          dp[i][j - 1][1] = now + 2, fg++;

        g = (now + t[i][j]) % (s[i][j] + w[i][j]);
        if (g < s[i][j])
          add = 1;
        else
          add = ((s[i][j] + w[i][j]) - g) + 1;

        if (dp[i][j][2] > (now + add))
          dp[i][j][2] = now + add, fg++;

        if (g >= s[i][j])
          add = 1;
        else
          add = (s[i][j] - g) + 1;

        if (dp[i][j][1] > (now + add))
          dp[i][j][1] = now + add, fg++;

        k = 1;
        now = dp[i][j][k];
        if (i && (dp[i - 1][j][3] > (now + 2)))
          dp[i - 1][j][3] = now + 2, fg++;

        if (((j + 1) < y) && (dp[i][j + 1][0] > (now + 2)))
          dp[i][j + 1][0] = now + 2, fg++;

        g = (now + t[i][j]) % (s[i][j] + w[i][j]);
        if (g < s[i][j])
          add = 1;
        else
          add = ((s[i][j] + w[i][j]) - g) + 1;

        if (dp[i][j][3] > (now + add))
          dp[i][j][3] = now + add, fg++;

        if (g >= s[i][j])
          add = 1;
        else
          add = (s[i][j] - g) + 1;

        if (dp[i][j][0] > (now + add))
          dp[i][j][0] = now + add, fg++;

        k = 2;
        now = dp[i][j][k];
        if (((i + 1) < x) && (dp[i + 1][j][0] > (now + 2)))
          dp[i + 1][j][0] = now + 2, fg++;

        if (j && (dp[i][j - 1][3] > (now + 2)))
          dp[i][j - 1][3] = now + 2, fg++;

        g = (now + t[i][j]) % (s[i][j] + w[i][j]);
        if (g < s[i][j])
          add = 1;
        else
          add = ((s[i][j] + w[i][j]) - g) + 1;

        if (dp[i][j][0] > (now + add))
          dp[i][j][0] = now + add, fg++;

        if (g >= s[i][j])
          add = 1;
        else
          add = (s[i][j] - g) + 1;

        if (dp[i][j][3] > (now + add))
          dp[i][j][3] = now + add, fg++;

        k = 3;
        now = dp[i][j][k];
        if (((i + 1) < x) && (dp[i + 1][j][1] > (now + 2)))
          dp[i + 1][j][1] = now + 2, fg++;

        if (((j + 1) < y) && (dp[i][j + 1][2] > (now + 2)))
          dp[i][j + 1][2] = now + 2, fg++;

        g = (now + t[i][j]) % (s[i][j] + w[i][j]);
        if (g < s[i][j])
          add = 1;
        else
          add = ((s[i][j] + w[i][j]) - g) + 1;

        if (dp[i][j][1] > (now + add))
          dp[i][j][1] = now + add, fg++;

        if (g >= s[i][j])
          add = 1;
        else
          add = (s[i][j] - g) + 1;

        if (dp[i][j][2] > (now + add))
          dp[i][j][2] = now + add, fg++;

      }


      if (!fg)
        break;

    }

    printf("Case #%d: %lld\n", ++count, dp[x - 1][y - 1][3]);
  }

  return 0;
}


