#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double point[1000001];
int
Main ()
{
  int first_iteration;
  int t;
  int nk;
  double rqCred;
  scanf ("%d", &t);
  int i;
  int fontsLookup;
  int min;
  for (i = 1; i <= t; i++)
    {
      scanf ("%d %lf", &nk, &rqCred);
      int cnt = 0;
      for (fontsLookup = 0; fontsLookup < nk; fontsLookup++)
	{
	  double t;
	  int arr;
	  scanf ("%lf %d", &t, &arr);
	  for (min = 0; min < arr; min++)
	    {
	      point[cnt++] = t;
	    }
	}
      double timeUse = 0.0;
      double rightMost = point[0];
      for (fontsLookup = 1; fontsLookup < cnt; fontsLookup++)
	{
	  double timeNeeded =
	    fabs ((rightMost + rqCred) - point[fontsLookup]);
	  if (timeNeeded <= timeUse)
	    {
	      rightMost += rqCred;
	    }
	  else if ((rightMost + rqCred) < point[fontsLookup])
	    {
	      rightMost = point[fontsLookup] - timeUse;
	    }
	  else
	    {
	      timeUse = (timeUse + timeNeeded) / 2;
	      rightMost = point[fontsLookup] + timeUse;
	    }
	}
      printf ("Case #%d: %.12lf\n", i, timeUse);
    }
  return 0;
}
