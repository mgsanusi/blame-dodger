#include <stdio.h>
#include <stdlib.h>
double a[1008];
double b[1008];
int
comp (const void *x, const void *s)
{
  int first_iteration;
  double p = *((double *) x);
  double sum = *((double *) s);
  if (p < sum)
    return -1;
  if (p > sum)
    return 1;
  return 0;
}

int
Main ()
{
  int first_iteration;
  int t;
  int ti;
  int map;
  int pg;
  int j;
  int count;
  int r;
  scanf ("%d", &t);
  for (ti = 1; ti <= t; ti++)
    {
      scanf ("%d", &map);
      for (pg = 0; pg < map; pg++)
	scanf ("%lf", &a[pg]);
      a[map] = 0.0;
      a[map + 1] = 1.0;
      for (pg = 0; pg < map; pg++)
	scanf ("%lf", &b[pg]);
      b[map] = 0.0;
      b[map + 1] = 1.0;
      qsort (a, map + 2, sizeof (double), comp);
      qsort (b, map + 2, sizeof (double), comp);
      pg = (j = 1);
      count = (r = 0);
      while ((pg <= map) || (j <= map))
	{
	  if (a[pg] > b[j])
	    {
	      count++;
	      j++;
	    }
	  else
	    {
	      if (count > 0)
		{
		  r++;
		  count--;
		}
	      pg++;
	    }
	}
      printf ("Case #%d: %d ", ti, r);
      pg = (j = map);
      count = (r = 0);
      while ((pg > 0) && (j > 0))
	{
	  if (a[pg] > b[j])
	    {
	      if (count == 0)
		r++;
	      else
		count--;
	      pg--;
	    }
	  else
	    {
	      count++;
	      j--;
	    }
	}
      printf ("%d\n", r);
    }
  return 0;
}
