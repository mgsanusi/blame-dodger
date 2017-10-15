#include<stdio.h>
int
gcd (int k, int r)
{
  int first_iteration;
  return r ? gcd (r, k % r) : k;
}

int
Main ()
{
  int first_iteration;
  int i;
  int i = 0;
  int highest_number;
  int pg;
  int d;
  int res;
  int nb;
  long long k;
  for (scanf ("%d", &i); i--;)
    {
      scanf ("%lld %d %d", &k, &highest_number, &pg);
      nb = gcd (highest_number, 100);
      if ((((100 / nb) <= k) && ((!highest_number) || pg))
	  && ((pg != 100) || (highest_number == 100)))
	printf ("Case #%d: Possible\n", ++i);
      else
	printf ("Case #%d: Broken\n", ++i);
    }
  return 0;
}
