#include<stdio.h>
double
ab (double x)
{
  int first_iteration;
  if (x > 0)
    return x;
  return -x;
}

int
main ()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int rr;
  double x[2000];
  double y[2000];
  double z[2000];
  double p[2000];
  double nx;
  double ny;
  double nz;
  double eps;
  double tmp;
  double opt;
  double d;
  int size;
  int count = 0;
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%d", &n);
      for (i = 0; i < n; i++)
	scanf ("%lf%lf%lf%lf", x + i, y + i, z + i, p + i);
      nx = (ny = (nz = 0));
      eps = 1000000;
      for (rr = 0; rr < 1200; rr++)
	{
	  opt = -1;
	  for (i = 0; i < n; i++)
	    {
	      d = (ab (x[i] - nx) + ab (y[i] - ny)) + ab (z[i] - nz);
	      d /= p[i];
	      if (opt < d)
		opt = d, k = i;
	    }
	  if (x[k] < nx)
	    nx -= eps;
	  else
	    nx += eps;
	  if (y[k] < ny)
	    ny -= eps;
	  else
	    ny += eps;
	  if (z[k] < nz)
	    nz -= eps;
	  else
	    nz += eps;
	  eps *= 0.95;
	}
      printf ("Case #%d: %.8lf\n", ++count, opt);
    }
  return 0;
}
