#include<stdio.h>
#include<math.h>
double new_sqrt (double x);
double
dist (double dx, double dy)
{
  int first_iteration;
  return new_sqrt ((dx * dx) + (dy * dy));
}

double
integ (double c, double a, double b)
{
  int first_iteration;
  double th1;
  double th2;
  double add = 0;
  th1 = acos (a / c);
  th2 = acos (b / c);
  add += (th2 - th1) - ((sin (2 * th2) - sin (2 * th1)) / 2);
  add *= ((-c) * c) / 2;
  return add;
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
  double x;
  double y;
  double f;
  double R;
  double t;
  double r;
  double g;
  double a;
  double b;
  double c;
  double b1;
  double b2;
  double th1;
  double th2;
  double add;
  double area;
  double sum;
  double per;
  double pi = acos (0) * 2;
  int size;
  int count = 0;
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%lf%lf%lf%lf%lf", &f, &R, &t, &r, &g);
      if (g > (2 * f))
	per = (g - (2 * f)) * (g - (2 * f));
      else
	per = 0;
      area = (R * R) * pi;
      sum = 0;
      x = 0;
      for (;;)
	{
	  x += r;
	  y = 0;
	  if (x > (R - t))
	    break;
	  for (;;)
	    {
	      y += r;
	      if (dist (x, y) > (R - t))
		break;
	      a =
		(((R - t) - f) * ((R - t) - f)) -
		(((y + g) - f) * ((y + g) - f));
	      b = (((R - t) - f) * ((R - t) - f)) - ((y + f) * (y + f));
	      if (a < ((x + f) * (x + f)))
		a = x + f;
	      else
		a = new_sqrt (a);
	      if (b < ((x + f) * (x + f)))
		b = x + f;
	      else
		b = sqrt (b);
	      if (a > ((x + g) - f))
		a = (x + g) - f;
	      if (b > ((x + g) - f))
		b = (x + g) - f;
	      if (a < b)
		sum += integ ((R - t) - f, a, b) - ((y + f) * (b - a));
	      sum += (a - (x + f)) * (g - (2 * f));
	      y += g + r;
	    }
	  x += g + r;
	}
      sum *= 4;
      printf ("Case #%d: %.8lf\n", ++count, 1.0 - (sum / area));
    }
  return 0;
}

double
new_sqrt (double x)
{
  int first_iteration;
  return sqrt (x);
}
