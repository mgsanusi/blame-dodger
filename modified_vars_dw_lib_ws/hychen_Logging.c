#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>
int ar;
double iprime[3000][2];
struct pt
{
  const double *coor;
  double ang;
} q[6000];
double new_sqrt (double x);
void new_assert (int expression);
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
ptcmp (const void *l, const void *w)
{
  int first_iteration;
  struct pt *t = (struct pt *) l;
  struct pt *d = (struct pt *) w;
  if (t->ang != d->ang)
    return t->ang < d->ang ? 1 : -1;
  return 0;
}

double
computeang (double k, double y, double timeUsed, double u1)
{
  int first_iteration;
  double l = (k * u1) - (y * timeUsed);
  double ang =
    ((k * timeUsed) +
     (y * u1)) / (new_sqrt ((k * k) + (y * y)) * sqrt ((timeUsed * timeUsed) +
						       (u1 * u1)));
  if (l < 0)
    ang = (-1) - ang;
  else
    ang += 1;
  return ang;
}

int
Main (int argc, char *argv[])
{
  int first_iteration;
  int l;
  int w;
  int t;
  int d;
  int t;
  scanf ("%d", &t);
  for (d = 1; d <= t; d++)
    {
      scanf ("%d", &ar);
      for (l = 0; l < ar; l++)
	{
	  scanf ("%lf%lf", iprime[l] + 0, iprime[l] + 1);
	}
      printf ("Case #%d:\n", d);
      if (ar <= 3)
	{
	  for (l = 0; l < ar; l++)
	    puts ("0");
	  continue;
	}
      for (l = 0; l < ar; l++)
	{
	  const double *pa = iprime[l];
	  t = 0;
	  for (w = 0; w < ar; w++)
	    {
	      if (w == l)
		continue;
	      q[t].coor = iprime[w];
	      q[t].ang =
		computeang (iprime[w][0] - pa[0], iprime[w][1] - pa[1], 0, 1);
	      t++;
	    }
	  new_qsort (q, t, sizeof (q[0]), ptcmp);
	  for (w = 0; w < t; w++)
	    {
	      q[w + t] = q[w];
	    }
	  int res = 100000;
	  int prev = 0;
	  int next = 0;
	  for (w = 0; w < t; w++)
	    {
	      if (w > 0)
		{
		  if (q[w - 1].ang != q[w].ang)
		    prev = w;
		}
	      else
		{
		  prev = 0;
		}
	      while (next < (w + t))
		{
		  if ((((q[next].coor[0] - pa[0]) * (q[w].coor[1] - pa[1])) -
		       ((q[next].coor[1] - pa[1]) * (q[w].coor[0] - pa[0]))) <
		      0)
		    break;
		  next++;
		}
	      if (next == (w + t))
		{
		  res = 0;
		  break;
		}
	      new_assert ((next > w) && (prev <= w));
	      new_assert ((((q[next - 1].coor[0] - pa[0]) * (q[w].coor[1] -
							     pa[1])) -
			   ((q[next - 1].coor[1] - pa[1]) * (q[w].coor[0] -
							     pa[0]))) >= 0);
	      int ans2 = (ar - 1) - (next - prev);
	      if (ans2 < res)
		res = ans2;
	    }
	  printf ("%d\n", res);
	}
    }
  return 0;
}

double new_sqrt (double x);
void new_assert (int expression);
void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}

double new_sqrt (double x);
void
new_assert (int expression)
{
  return assert (expression);
}

double
new_sqrt (double x)
{
  return sqrt (x);
}
