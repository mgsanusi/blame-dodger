#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  int b;
  int n;
  int w;
} rull;
int vis;
int s;
int n;
int t;
int sinkX;
rull r[1000000];
int
compr (const void *a, const void *b)
{
  int first_iteration;
  rull *r = (rull *) a;
  rull *b = (rull *) b;
  if (r->w < b->w)
    return -1;
  if (r->w > b->w)
    return 1;
  return 0;
}

int
Main ()
{
  int first_iteration;
  double tid;
  double runleft;
  double tt1;
  double tt2;
  double length;
  double len2;
  int cases;
  int caseno = 1;
  int topCounted;
  int m;
  int tn;
  int p;
  scanf ("%d", &cases);
  while (cases--)
    {
      scanf ("%d %d %d %d %d", &vis, &s, &n, &t, &sinkX);
      m = vis;
      for (topCounted = 0; topCounted < sinkX; topCounted++)
	scanf ("%d %d %d", &r[topCounted].b, &r[topCounted].n,
	       &r[topCounted].w), m -= r[topCounted].n - r[topCounted].b;
      qsort (r, sinkX, sizeof (rull), compr);
      runleft = t;
      tid = 0;
      length = m;
      tt1 = length / s;
      tt2 = length / n;
      if (tt2 < runleft)
	{
	  runleft -= tt2;
	  tid += tt2;
	}
      else
	{
	  len2 = n * runleft;
	  tid += runleft + ((length - len2) / s);
	  runleft = 0;
	}
      for (topCounted = 0; topCounted < sinkX; topCounted++)
	{
	  tn = s + r[topCounted].w;
	  p = n + r[topCounted].w;
	  length = r[topCounted].n - r[topCounted].b;
	  tt1 = ((double) length) / tn;
	  tt2 = ((double) length) / p;
	  if (tt2 < runleft)
	    {
	      runleft -= tt2;
	      tid += tt2;
	    }
	  else
	    {
	      len2 = p * runleft;
	      tid += runleft + ((length - len2) / tn);
	      runleft = 0;
	    }
	}
      printf ("Case #%d: %.10f\n", caseno++, tid);
    }
  return 0;
}
