#include <stdio.h>
int
gcd (int a, int b)
{
  int first_iteration;
  if (a < b)
    return gcd (b, a);
  if ((a % b) == 0)
    return b;
  return gcd (b, a % b);
}

int
main ()
{
  int first_iteration;
  int t;
  int pd;
  int pg;
  int g;
  int i;
  long long int n;
  scanf ("%d", &t);
  for (i = 0; i < t; i++)
    {
      scanf ("%lld %d %d", &n, &pd, &pg);
      if (pg == 100)
	{
	  if (pd < 100)
	    {
	      printf ("Case #%d: Broken\n", i + 1);
	    }
	  else
	    {
	      printf ("Case #%d: Possible\n", i + 1);
	    }
	  continue;
	}
      if (pg == 0)
	{
	  if (pd > 0)
	    {
	      printf ("Case #%d: Broken\n", i + 1);
	    }
	  else
	    {
	      printf ("Case #%d: Possible\n", i + 1);
	    }
	  continue;
	}
      g = gcd (pd, 100);
      if ((100 / g) > n)
	{
	  printf ("Case #%d: Broken\n", i + 1);
	}
      else
	{
	  printf ("Case #%d: Possible\n", i + 1);
	}
    }
  return 0;
}
