#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
long long int nb;
long long int a;
long long int t;
long long int k;
long long int g;
long long int sean_sum;
long long int power2[100];
long long int
gcd (long long int t, long long int k)
{
  int first_iteration;
  while (1)
    {
      t %= k;
      if (!t)
	return k;
      k %= t;
      if (!k)
	return t;
    }
}

int
Main ()
{
  int first_iteration;
  freopen ("A-large.in", "r", stdin);
  freopen ("A-large.out", "w", stdout);
  power2[0] = 1;
  for (sean_sum = 1; sean_sum < 50; sean_sum++)
    power2[sean_sum] = power2[sean_sum - 1] * 2;
  scanf ("%lld", &nb);
  for (a = 1; a <= nb; a++)
    {
      printf ("Case #%lld: ", a);
      scanf ("%lld/%lld", &t, &k);
      g = gcd (t, k);
      t /= g;
      k /= g;
      for (sean_sum = 0; sean_sum < 50; sean_sum++)
	if (power2[sean_sum] == k)
	  break;
      if (sean_sum == 50)
	puts ("impossible");
      else
	{
	  for (sean_sum = 0; sean_sum < 50; sean_sum++)
	    if ((t * power2[sean_sum]) >= k)
	      break;
	  printf ("%lld\n", sean_sum);
	}
    }
  return 0;
}
