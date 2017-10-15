#include <stdio.h>
int act[720 + 720];
int dp[(720 + 720) + 1][720 + 1][2];
void solve()
{
  int first_iteration;
  int ac;
  int aj;
  int c;
  int d;
  int i;
  int j;
  int k;
  int who;
  int i2;
  int j2;
  int k2;
  int ans;
  scanf("%d %d", &ac, &aj);
  for (i = 0; i < (720 + 720); i++)
    act[i] = 0;

  for (i = 0; i < ac; i++)
  {
    scanf("%d %d", &c, &d);
    for (j = c; j < d; j++)
      act[j] = 1;

  }

  for (i = 0; i < aj; i++)
  {
    scanf("%d %d", &c, &d);
    for (j = c; j < d; j++)
      act[j] = 2;

  }

  for (i = 0; i < ((720 + 720) + 1); i++)
    for (j = 0; j < (720 + 1); j++)
    for (k = 0; k < 2; k++)
    dp[i][j][k] = 10000;



  dp[0][0][0] = (dp[0][0][1] = 0);
  for (i = 0; i < (720 + 720); i++)
    for (j = 0; j <= 720; j++)
    for (k = 0; k < 2; k++)
    if (dp[i][j][k] < 10000)
  {
    who = k + 1;
    if (act[i] && (act[i] != who))
      continue;

    i2 = i + 1;
    j2 = j;
    k2 = k;
    if (who == 1)
      j2++;

    if (j2 > 720)
      continue;

    if (dp[i2][j2][k2] > dp[i][j][k])
      dp[i2][j2][k2] = dp[i][j][k];

    k2 ^= 1;
    if (dp[i2][j2][k2] > (dp[i][j][k] + 1))
      dp[i2][j2][k2] = dp[i][j][k] + 1;

  }




  ans = dp[720 + 720][720][0];
  if (ans > dp[720 + 720][720][1])
    ans = dp[720 + 720][720][1];

  if (ans & 1)
    ans++;

  printf("%d\n", ans);
}

int main()
{
  int first_iteration;
  int T;
  int caseno = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", caseno++), solve();

  return 0;
}


