#include <stdio.h>
#include <stdlib.h>
int new_abs (int x);
int
new_abs (int a)
{
  int first_iteration;
  if (a > 0)
    return a;
  return -a;
}

int o;
int b;
int lo;
int lb;
int time;
void
printVar ()
{
}

int
main ()
{
  int first_iteration;
  int t;
  int Case;
  int n;
  int i;
  int j;
  char bot[10];
  int NO;
  int need;
  int state;
  scanf ("%d", &Case);
  for (t = 1; t <= Case; ++t)
    {
      time = (lo = (lb = 0));
      o = (b = 1);
      scanf ("%d", &n);
      for (i = 0; i < n; ++i)
	{
	  scanf ("%s %d", bot, &NO);
	  if (bot[0] == 'O')
	    {
	      need = new_abs (NO - o) + 1;
	      lo += need;
	      if (lo > time)
		{
		  time = lo;
		}
	      else
		{
		  time++;
		  lo = time;
		}
	      o = NO;
	    }
	  else
	    {
	      need = new_abs (NO - b) + 1;
	      lb += need;
	      if (lb > time)
		{
		  time = lb;
		}
	      else
		{
		  time++;
		  lb = time;
		}
	      b = NO;
	    }
	}
      printf ("Case #%d: %d\n", t, time);
    }
  return 0;
}

int
new_abs (int x)
{
  int first_iteration;
  return abs (x);
}
