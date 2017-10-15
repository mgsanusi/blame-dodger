#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int no[1234][2];
int run[1234];
int oppo;
int
Main ()
{
  int first_iteration;
  int Case = 0;
  int c;
  int lo;
  int need_x;
  int max;
  int star;
  int step;
  scanf ("%d", &c);
  while (c--)
    {
      scanf ("%d", &oppo);
      for (lo = 0; lo < oppo; ++lo)
	{
	  scanf ("%d %d", &no[lo][0], &no[lo][1]);
	}
      memset (run, 0, sizeof (run));
      star = (step = 0);
      while (1)
	{
	  for (lo = 0, max = -1; lo < oppo; ++lo)
	    {
	      if ((star >= no[lo][1]) && (run[lo] < 2))
		{
		  max = lo;
		  break;
		}
	      else if ((star >= no[lo][0]) && (run[lo] < 1))
		{
		  if ((max == (-1)) || (no[max][1] < no[lo][1]))
		    {
		      max = lo;
		    }
		}
	    }
	  if (max == (-1))
	    break;
	  if (star >= no[max][1])
	    {
	      star += 2 - run[max];
	      run[max] = 2;
	    }
	  else
	    {
	      star += 1 - run[max];
	      run[max] = 1;
	    }
	  ++step;
	}
      for (lo = 0; run[lo] == 2; ++lo)
	;
      if (lo < oppo)
	{
	  printf ("Case #%d: Too Bad\n", ++Case);
	}
      else
	{
	  printf ("Case #%d: %d\n", ++Case, step);
	}
    }
  return 0;
}
