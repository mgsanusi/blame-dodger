#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int
Main (void)
{
  int i;
  int j;
  int fpIn;
  int num;
  int cases;
  int i;
  int h2;
  int x2;
  int y2;
  int exy;
  int at;
  double t;
  double t;
  double v;
  double t;
  double s;
  for (scanf ("%d", &i), j = 1; j <= i; j++)
    {
      scanf ("%d%d%d", &fpIn, &num, &cases);
      i = (h2 = 0);
      for (x2 = 0; x2 <= fpIn; x2++)
	{
	  for (y2 = 0; y2 <= num; y2++)
	    {
	      for (exy = 0; exy <= fpIn; exy++)
		{
		  for (at = 0; at <= num; at++)
		    {
		      t =
			sqrt (((i - x2) * (i - x2)) +
			      ((h2 - y2) * (h2 - y2)));
		      t =
			sqrt (((x2 - exy) * (x2 - exy)) +
			      ((y2 - at) * (y2 - at)));
		      v =
			sqrt (((exy - i) * (exy - i)) +
			      ((at - h2) * (at - h2)));
		      t = ((t + t) + v) / 2;
		      s = ((t * (t - t)) * (t - t)) * (t - v);
		      if (fabs ((4 * s) - (cases * cases)) <= 1e-6)
			{
			  break;
			}
		    }
		  if (at <= num)
		    {
		      break;
		    }
		}
	      if (exy <= fpIn)
		{
		  break;
		}
	    }
	  if (y2 <= num)
	    {
	      break;
	    }
	}
      printf ("Case #%d: ", j);
      if (x2 <= fpIn)
	{
	  printf ("%d %d %d %d %d %d\n", i, h2, x2, y2, exy, at);
	}
      else
	{
	  printf ("IMPOSSIBLE\n");
	}
    }
  return 0;
}
