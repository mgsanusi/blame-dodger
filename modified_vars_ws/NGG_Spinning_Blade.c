#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  int w;
  int app;
} path_t;
path_t path[1010];
int
cmp (const void *a, const void *b)
{
  return (*((int *) a)) - (*((int *) b));
}

int
Main (void)
{
  int out;
  int target;
  scanf ("%d", &out);
  for (target = 1; target <= out; target++)
    {
      int k;
      int c;
      int r;
      int tn;
      int i;
      int j;
      double out;
      double ret = 0;
      scanf ("%d %d %d %lf %d", &k, &c, &r, &out, &tn);
      j = k;
      r -= c;
      for (i = 0; i < tn; i++)
	{
	  int a;
	  int b;
	  int w;
	  scanf ("%d %d %d", &a, &b, &w);
	  path[i].w = w + c;
	  path[i].app = b - a;
	  k -= path[i].app;
	}
      path[tn].app = k;
      path[tn].w = c;
      qsort (path, tn + 1, 2 * (sizeof (int)), cmp);
      for (i = 0; i <= tn; i++)
	{
	  double runtime = ((double) path[i].app) / (path[i].w + r);
	  if (runtime <= out)
	    {
	      out -= runtime;
	      ret += runtime;
	    }
	  else
	    {
	      double app = ((double) path[i].app) - ((path[i].w + r) * out);
	      ret += out;
	      ret += app / path[i].w;
	      out = 0;
	    }
	}
      printf ("Case #%d: %.8lf\n", target, ret);
    }
  return 0;
}
