#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_atoi (const char *str);
int
Main ()
{
  int i;
  int run;
  int buf;
  int l;
  int p1;
  int n;
  int length;
  int size;
  int cnt = 0;
  char e[10000];
  int dp[20];
  char *w = "welcome to code jam";
  gets (e);
  size = new_atoi (e);
  while (size--)
    {
      gets (e);
      for (i = 0;; i++)
	if (e[i] < ' ')
	  break;
      length = i;
      for (i = 0; i < 20; i++)
	dp[i] = 0;
      dp[0] = 1;
      for (i = 0; i < length; i++)
	for (buf = 18; buf >= 0; buf--)
	  if (w[buf] == e[i])
	    dp[buf + 1] = (dp[buf + 1] + dp[buf]) % 10000;
      printf ("Case #%d: %04d\n", ++cnt, dp[19]);
    }
  return 0;
}

int
new_atoi (const char *str)
{
  return atoi (str);
}
