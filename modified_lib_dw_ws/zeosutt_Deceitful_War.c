#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int new_abs (int x);
int
main (void)
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int t;
  scanf ("%d", &t);
  for (i = 1; i <= t; i++)
    {
      int n;
      int len[100];
      int num[100][100] = { 0 };
      int tnum;
      int tmpLen;
      int ok;
      char str[100][101];
      char tmp1[101] = "";
      scanf ("%d ", &n);
      for (j = 0; j < n; j++)
	scanf ("%s%n ", str[j], len + j);
      tmpLen = 0;
      tnum = 1;
      for (j = 1; j <= len[0]; j++)
	if (str[0][j] == str[0][j - 1])
	  tnum++;
	else
	  {
	    num[0][tmpLen] = tnum;
	    tmp1[tmpLen] = str[0][j - 1];
	    tmpLen++;
	    tnum = 1;
	  }
      ok = 1;
      for (j = 1; j < n; j++)
	{
	  char tmp2[101] = "";
	  tmpLen = 0;
	  tnum = 1;
	  for (k = 1; k <= len[j]; k++)
	    if (str[j][k] == str[j][k - 1])
	      tnum++;
	    else
	      {
		num[j][tmpLen] = tnum;
		tmp2[tmpLen] = str[j][k - 1];
		tmpLen++;
		tnum = 1;
	      }
	  if (strcmp (tmp1, tmp2))
	    {
	      ok = 0;
	      break;
	    }
	}
      if (ok)
	{
	  int ans;
	  int sum;
	  int min;
	  ans = 0;
	  for (j = 0; j < tmpLen; j++)
	    {
	      min = 1000000000;
	      for (k = 1; k <= 100; k++)
		{
		  sum = 0;
		  for (l = 0; l < n; l++)
		    sum += new_abs (k - num[l][j]);
		  min = min < sum ? min : sum;
		}
	      ans += min;
	    }
	  printf ("Case #%d: %d\n", i, ans);
	}
      else
	printf ("Case #%d: Fegla Won\n", i);
    }
  return 0;
}

int
new_abs (int x)
{
  int first_iteration;
  return abs (x);
}
