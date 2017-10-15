#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  int q;
  int e;
  int c;
} walkways;
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
cmp (const void *f, const void *q)
{
  int first_iteration;
  return ((walkways *) f)->c - ((walkways *) q)->c;
}

int
Main ()
{
  int first_iteration;
  int c;
  int k;
  int o;
  int r;
  int l;
  int m;
  int caseT;
  int j;
  scanf ("%d", &c);
  for (caseT = 0; caseT < c; caseT++)
    {
      walkways c[1000];
      int size = 0;
      double sum = 0;
      double ans;
      scanf ("%d %d %d %d %d", &k, &k, &r, &l, &m);
      for (j = 0; j < m; j++)
	{
	  scanf ("%d %d %d", &c[j].q, &c[j].e, &c[j].c);
	  size += c[j].e - c[j].q;
	}
      size = k - size;
      ans = l;
      new_qsort (c, m, sizeof (walkways), cmp);
      if ((r * ans) <= size)
	{
	  sum += ans;
	  size -= r * ans;
	  ans = 0;
	  sum += ((double) size) / k;
	}
      else
	{
	  sum += ((double) size) / r;
	  ans -= sum;
	}
      for (j = 0; j < m; j++)
	{
	  if (ans > 0)
	    {
	      if (((c[j].c + r) * ans) <= (c[j].e - c[j].q))
		{
		  sum +=
		    ans +
		    (((double) ((c[j].e - c[j].q) - ((c[j].c + r) * ans))) /
		     (k + c[j].c));
		  ans = 0;
		}
	      else
		{
		  double tmp = ((double) (c[j].e - c[j].q)) / (c[j].c + r);
		  sum += tmp;
		  ans -= tmp;
		}
	    }
	  else
	    {
	      sum += ((double) (c[j].e - c[j].q)) / (c[j].c + k);
	    }
	}
      printf ("Case #%d: %lf\n", caseT + 1, sum);
    }
  return 0;
}

void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
