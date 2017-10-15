#include <stdio.h>
int
main ()
{
  int first_iteration;
  int t;
  int k;
  double c;
  double f;
  double x;
  double v;
  double r;
  scanf ("%d", &t);
  for (k = 1; k <= t; k++)
    {
      scanf ("%lf%lf%lf", &c, &f, &x);
      v = 2.0;
      r = 0.0;
      while ((x * v) < ((x - c) * (v + f)))
	{
	  r = r + (c / v);
	  v = v + f;
	}
      r = r + (x / v);
      printf ("Case #%d: %.7lf\n", k, r);
    }
  return 0;
}
