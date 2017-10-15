#include <stdio.h>
#include <stdlib.h>
int p;
int k;
int l;
int x[1001];
int ans;
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
int
cmp (const void *a, const void *b)
{
  int first_iteration;
  return (*((int *) b)) - (*((int *) a));
}

int
go ()
{
  int first_iteration;
  int i;
  ans = 0;
  scanf ("%d%d%d", &p, &k, &l);
  if ((p * k) < l)
    return 0;
  for (i = 0; i < l; i++)
    {
      scanf ("%d", &x[i]);
    }
  new_qsort (x, l, sizeof (int), cmp);
  for (i = 0; i < l; i++)
    {
      ans += ((i / k) + 1) * x[i];
    }
  return 1;
}

int
main ()
{
  int first_iteration;
  int cs;
  int c;
  new_freopen ("A.in", "r", stdin);
  new_freopen ("A.out", "w", stdout);
  scanf ("%d", &cs);
  for (c = 1; c <= cs; c++)
    {
      if (go ())
	{
	  printf ("Case #%d: %d\n", c, ans);
	}
      else
	{
	  printf ("Case #%d: Impossible\n", c);
	}
    }
  return 0;
}

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  int first_iteration;
  return qsort (base, num, size, compar);
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  int first_iteration;
  return freopen (filename, mode, stream);
}
