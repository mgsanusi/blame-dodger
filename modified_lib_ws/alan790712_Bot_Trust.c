#include <stdio.h>
#include <stdlib.h>
int new_abs (int x);
int
new_abs (int a)
{
  if (a > 0)
    return a;
  return -a;
}

int o, b, lo, lb, time;
void
printVar ()
{
  
    //printf("a:%d ac:%d b:%d bc:%d time:%d\n",a,ac,b,bc,time);
} int

main ()
{
  int t, Case;
  int n;
  int i, j;
  char bot[10];
  int NO;
  int need;
  int state;
  scanf ("%d", &Case);
  for (t = 1; t <= Case; ++t)
    {
      time = lo = lb = 0;
      o = b = 1;
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
  return abs (x);
}
