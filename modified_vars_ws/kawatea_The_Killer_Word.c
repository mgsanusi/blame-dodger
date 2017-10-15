#include <stdio.h>
int
gcd (int a, int b)
{
  if (a < b)
    return gcd (b, a);
  if ((a % b) == 0)
    return b;
  return gcd (b, a % b);
}

int
Main ()
{
  int t;
  int tcases;
  int primes;
  int x;
  int total;
  long long int n;
  scanf ("%d", &t);
  for (total = 0; total < t; total++)
    {
      scanf ("%lld %d %d", &n, &tcases, &primes);
      if (primes == 100)
	{
	  if (tcases < 100)
	    {
	      printf ("Case #%d: Broken\n", total + 1);
	    }
	  else
	    {
	      printf ("Case #%d: Possible\n", total + 1);
	    }
	  continue;
	}
      if (primes == 0)
	{
	  if (tcases > 0)
	    {
	      printf ("Case #%d: Broken\n", total + 1);
	    }
	  else
	    {
	      printf ("Case #%d: Possible\n", total + 1);
	    }
	  continue;
	}
      x = gcd (tcases, 100);
      if ((100 / x) > n)
	{
	  printf ("Case #%d: Broken\n", total + 1);
	}
      else
	{
	  printf ("Case #%d: Possible\n", total + 1);
	}
    }
  return 0;
}
