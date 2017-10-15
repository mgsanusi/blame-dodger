#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_atoi(const char *str);
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int len;
  int size;
  int count = 0;
  char in[10000];
  int dp[20];
  char *w = "welcome to code jam";
  gets(in);
  size = new_atoi(in);
  while (size--)
  {
    gets(in);
    for (i = 0;; i++)
      if (in[i] < ' ')
      break;


    len = i;
    for (i = 0; i < 20; i++)
      dp[i] = 0;

    dp[0] = 1;
    for (i = 0; i < len; i++)
      for (k = 18; k >= 0; k--)
      if (w[k] == in[i])
      dp[k + 1] = (dp[k + 1] + dp[k]) % 10000;



    printf("Case #%d: %04d\n", ++count, dp[19]);
  }

  return 0;
}

int new_atoi(const char *str)
{
  int first_iteration;
  return atoi(str);
}


