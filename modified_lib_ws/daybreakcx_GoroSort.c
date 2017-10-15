#include <stdio.h>
int ti, tn, i, n, d, res;
int
main ()
{
  scanf ("%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
    {
      scanf ("%d", &n);
      for (i = 1, res = 0; i <= n; ++i)
	{
	  scanf ("%d", &d);
	  res += (d != i);
	}
      printf ("Case #%d: %d\n", ti, res);
    }
  return 0;
}
