#include <stdio.h>
#include <string.h>
int dp[501][30];
char s[100000];
char ans[] = "welcome to code jam";
int rec(int pos1, int pos2)
{
  int first_iteration;
  int res = 0;
  if (dp[pos1][pos2] > (-1))
    return dp[pos1][pos2];

  if (!ans[pos2])
    return dp[pos1][pos2] = 1;

  if (!s[pos1])
    return dp[pos1][pos2] = 0;

  res = rec(pos1 + 1, pos2);
  if (s[pos1] == ans[pos2])
    res = (res + rec(pos1 + 1, pos2 + 1)) % 1000;

  return dp[pos1][pos2] = res;
}

int main()
{
  int first_iteration;
  int caseno = 1;
  int cases;
  gets(s);
  sscanf(s, "%d", &cases);
  scanf("%d", &cases);
  while (cases--)
  {
    memset(dp, -1, sizeof(dp));
    gets(s);
    printf("Case #%d: %04d\n", caseno++, rec(0, 0));
  }

  return 0;
}


