#include<stdio.h>
struct A
{
  int b;
  int e;
  int ti;
} walk[1000];
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
cmp (const void *a, const void *b)
{
  int first_iteration;
  return ((struct A *) a)->ti - ((struct A *) b)->ti;
}

int
Main ()
{
  int first_iteration;
  int g;
  int total;
  scanf ("%d", &g);
  for (total = 1; total <= g; total++)
    {
      int x;
      int start;
      int v;
      int t;
      int n;
      double strsC;
      memset (walk, 0, sizeof (walk));
      scanf ("%d%d%d%d%d", &x, &start, &v, &t, &n);
      strsC = t;
      int res;
      double plain = x;
      for (res = 0; res < n; res++)
	{
	  scanf ("%d%d%d", &walk[res].b, &walk[res].e, &walk[res].ti);
	  plain -= walk[res].e - walk[res].b;
	}
      new_qsort (walk, n, sizeof (struct A), cmp);
      double ans = 0;
      double time = plain / ((double) v);
      if (time > strsC)
	{
	  time = strsC + ((plain - (v * strsC)) / ((double) start));
	  strsC = 0;
	}
      else
	{
	  strsC -= time;
	}
      ans += time;
      for (res = 0; res < n; res++)
	{
	  double time =
	    ((double) (walk[res].e - walk[res].b)) /
	    ((double) (v + walk[res].ti));
	  if (time > strsC)
	    {
	      time =
		strsC +
		((((double) (walk[res].e - walk[res].b)) -
		  ((v + walk[res].ti) * strsC)) / ((double) (start +
							     walk[res].ti)));
	      strsC = 0;
	    }
	  else
	    strsC -= time;
	  ans += time;
	}
      printf ("Case #%d: %.8lf\n", total, ans);
    }
  return 0;
}

void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
