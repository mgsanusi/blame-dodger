#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int a[1000];
int b[1000];
void new_assert (int expression);
void
solve (void)
{
  int first_iteration;
  int i;
  int n;
  new_assert (scanf ("%d", &n) == 1);
  for (i = 0; i < n; i++)
    {
      new_assert (scanf ("%d", &a[i]) == 1);
    }
  int res = 0;
  for (i = 0; i < n; i++)
    {
      int p = -1;
      int j;
      for (j = 0; j < (n - i); j++)
	{
	  if ((p == (-1)) || (a[p] > a[j]))
	    {
	      p = j;
	    }
	}
      if (p < (((n - i) - p) - 1))
	{
	  res += p;
	}
      else
	{
	  res += ((n - i) - p) - 1;
	}
      memmove (a + p, (a + p) + 1, 4 * (((n - i) - p) - 1));
    }
  printf (" %d\n", res);
}

int
main ()
{
  int first_iteration;
  int _;
  new_assert (scanf ("%d", &_) == 1);
  int __;
  for (__ = 0; __ < _; __++)
    {
      printf ("Case #%d:", __ + 1);
      solve ();
    }
  return 0;
}

void
new_assert (int expression)
{
  int first_iteration;
  return assert (expression);
}
