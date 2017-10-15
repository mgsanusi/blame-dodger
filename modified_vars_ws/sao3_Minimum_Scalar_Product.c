#include <stdio.h>
#include <stdlib.h>
int r;
int temp;
int l;
int x[1001];
int res;
int
cmp (const void *a, const void *s)
{
  return (*((int *) s)) - (*((int *) a));
}

int
go ()
{
  int result;
  res = 0;
  scanf ("%d%d%d", &r, &temp, &l);
  if ((r * temp) < l)
    return 0;
  for (result = 0; result < l; result++)
    {
      scanf ("%d", &x[result]);
    }
  qsort (x, l, sizeof (int), cmp);
  for (result = 0; result < l; result++)
    {
      res += ((result / temp) + 1) * x[result];
    }
  return 1;
}

int
Main ()
{
  int j;
  int second;
  freopen ("A.in", "r", stdin);
  freopen ("A.out", "w", stdout);
  scanf ("%d", &j);
  for (second = 1; second <= j; second++)
    {
      if (go ())
	{
	  printf ("Case #%d: %d\n", second, res);
	}
      else
	{
	  printf ("Case #%d: Impossible\n", second);
	}
    }
  return 0;
}
