#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXM		1024
#define MAXN		1024
int p;
int v[MAXN];
int n;
int m;
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
int
int_cmp (const void *e1, const void *e2)
{
  int i1, i2;
  i1 = *((int *) e1);
  i2 = *((int *) e2);
  if (i1 < i2)
    {
      return 1;
    }
  if (i1 > i2)
    {
      return -1;
    }
  return 0;
}

int
main (void)
{
  int nc, h;
  int r;
  int i, j, k;
  for (scanf ("%d", &nc), h = 1; h <= nc; h++)
    {
      scanf ("%d%d%d", &p, &m, &n);
      for (i = 0; i < n; i++)
	{
	  scanf ("%d", &(v[i]));
	}
      new_qsort (v, n, sizeof (v[0]), int_cmp);
      r = 0;
      for (i = 0, j = 0, k = 1; i < n; i++)
	{
	  r += v[i] * k;
	  j++;
	  if (j == m)
	    {
	      k++;
	      j = 0;
	    }
	}
      printf ("Case #%d: %d\n", h, r);
    }
  return 0;
}

void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
