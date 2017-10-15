#include<stdio.h>
#include<string.h>
int pre[1 << 21];
int str[32];
int n;
int now[32];
int supNum[32];
int maxtime;
int tvy;
int new_puts (const char *str);
int
Main ()
{
  int inversions;
  int cs = 0;
  int ct;
  int count;
  int t;
  int sum;
  int r;
  for (scanf ("%d", &inversions); inversions--;)
    {
      scanf ("%d", &n);
      for (ct = 0; ct < n; ct++)
	scanf ("%d", &str[ct]);
      memset (pre, 0xff, sizeof (pre));
      pre[0] = (r = 0);
      for (ct = (sum = 0); (ct < n) && (!r); sum += str[ct], ct++)
	for (count = sum; (count >= 0) && (!r); count--)
	  if (pre[count] >= 0)
	    {
	      if (pre[count + str[ct]] < 0)
		pre[count + str[ct]] = count;
	      else
		{
		  r = 1;
		  for (maxtime = 0, t = count + str[ct]; t > 0; t = pre[t])
		    now[maxtime++] = t - pre[t];
		  for (tvy = 0, t = count; t > 0; t = pre[t])
		    supNum[tvy++] = t - pre[t];
		  supNum[tvy++] = str[ct];
		}
	    }
      printf ("Case #%d:\n", ++cs);
      if (!r)
	{
	  new_puts ("Impossible");
	  continue;
	}
      for (ct = 0; ct < maxtime; ct++)
	{
	  for (count = 0; count < (tvy - 1); count++)
	    if (now[ct] == supNum[count])
	      break;
	  if (count < (tvy - 1))
	    {
	      now[ct] = now[maxtime - 1];
	      maxtime--;
	      ct--;
	      supNum[count] = supNum[tvy - 2];
	      supNum[tvy - 2] = supNum[tvy - 1];
	      tvy--;
	    }
	}
      for (ct = 0; ct < (maxtime - 1); ct++)
	printf ("%d ", now[ct]);
      printf ("%d\n", now[ct]);
      for (ct = 0; ct < (tvy - 1); ct++)
	printf ("%d ", supNum[ct]);
      printf ("%d\n", supNum[ct]);
    }
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
