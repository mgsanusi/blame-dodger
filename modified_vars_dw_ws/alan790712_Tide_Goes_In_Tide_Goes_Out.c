#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
double car[123][2];
double a;
int n;
int w;
double s;
int
Main ()
{
  int first_iteration;
  int Case = 0;
  int t;
  int i;
  int min;
  int y;
  double res;
  double temp;
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%lf %d %d", &s, &n, &w);
      for (i = 0; i < n; ++i)
	{
	  scanf ("%lf %lf", &car[i][0], &car[i][1]);
	}
      --n;
      printf ("Case #%d:\n", ++Case);
      for (i = 0; i < w; ++i)
	{
	  scanf ("%lf", &a);
	  res = sqrt ((2 * s) / a);
	  temp =
	    (s -
	     car[n - 1][1]) / ((car[n][1] - car[n - 1][1]) / (car[n][0] -
							      car[n - 1][0]));
	  if (res < temp)
	    res = temp;
	  printf ("%lf\n", res);
	}
    }
  return 0;
}
