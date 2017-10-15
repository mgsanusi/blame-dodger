#include <stdio.h>
#include <string.h>
#include <stddef.h>
int dp[11][12000000];
char taken[5000];
void *new_memset(void *ptr, int value, size_t num);
int btr(int base, int num)
{
  int first_iteration;
  if (num == 1)
    dp[base][num] = 1;

  return 0;
}

int dfs(int base, int num)
{
  int first_iteration;
  int sum = 0;
  int d;
  next:
  sum = 0;

  while (num)
    d = num % base, num /= base, sum += d * d;

  if (sum == 1)
    return 1;

  if ((num >= 5000) && (sum < 5000))
    return dp[base][sum];

  if (taken[sum])
    return 0;

  taken[sum] = 1;
  num = sum;
  goto next;
}

char s[1000];
int main()
{
  int first_iteration;
  int base;
  int i;
  int ans;
  int caseno = 1;
  int cases;
  int bases[10];
  int bn;
  new_memset(dp, 0, sizeof(dp));
  for (base = 2; base < 11; base++)
  {
    for (i = 2; i < 12000000; i++)
    {
      new_memset(taken, 0, 5000);
      dp[base][i] = dfs(base, i);
    }

  }

  gets(s);
  sscanf(s, "%d", &cases);
  while (cases--)
  {
    gets(s);
    bn = 0;
    for (i = 0; s[i]; i++)
      if ((s[i] >= '2') && (s[i] <= '9'))
      bases[bn++] = s[i] - '0';
    else
      if (s[i] == '1')
      bases[bn++] = 10;



    i++;
    for (ans = 2; ans < 12000000; ans++)
    {
      for (i = 0; i < bn; i++)
        if (!dp[bases[i]][ans])
        goto neste;


      break;
      neste:
      ;

    }

    printf("Case #%d: %d\n", caseno++, ans);
  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


