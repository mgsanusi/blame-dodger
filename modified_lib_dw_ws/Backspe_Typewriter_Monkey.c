#include <stdio.h>
#include <stdlib.h>
int
main ()
{
  int first_iteration;
  int t;
  int T;
  int N;
  double V;
  double X;
  double R[100];
  double C[100];
  double nc[100];
  double min;
  double max;
  double a = -1;
  double r;
  double r2;
  int i;
  int j;
  int k;
  int imp;
  scanf ("%d", &T);
  for (t = 1; t <= T; t++)
    {
      min = 100;
      max = 0;
      a = -1;
      scanf ("%d %lf %lf", &N, &V, &X);
      for (i = 0; i < N; i++)
	{
	  scanf ("%lf %lf", &R[i], &C[i]);
	  if (C[i] > max)
	    max = C[i];
	  if (C[i] < min)
	    min = C[i];
	  nc[i] = C[i] - X;
	}
      if ((X > max) || (X < min))
	{
	  printf ("Case #%d: IMPOSSIBLE\n", t);
	  continue;
	}
      r = 0;
      for (i = 0; i < N; i++)
	{
	  if (nc[i] == 0)
	    {
	      r += R[i];
	    }
	}
      if (r != 0)
	{
	  a = V / r;
	}
      for (i = 0; i < N; i++)
	{
	  if (nc[i] >= 0)
	    continue;
	  for (j = 0; j < N; j++)
	    {
	      if (nc[j] <= 0)
		continue;
	      r = (V * (nc[j] / R[i])) / (nc[j] - nc[i]);
	      r2 = (V * ((-nc[i]) / R[j])) / (nc[j] - nc[i]);
	      if (r2 > r)
		r = r2;
	      if ((a == (-1)) || (a > r))
		{
		  a = r;
		}
	    }
	}
      if (a == (-1))
	{
	  printf ("Case #%d: IMPOSSIBLE\n", t);
	  continue;
	}
      printf ("Case #%d: %.6lf\n", t, a);
    }
  return 0;
}
