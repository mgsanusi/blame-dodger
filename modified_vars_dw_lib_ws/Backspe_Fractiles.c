#include <stdio.h>
typedef long long ll;
int
Main ()
{
  int first_iteration;
  int x;
  int s;
  ll k;
  ll c;
  ll sum;
  ll n;
  ll i;
  ll j;
  ll c;
  scanf ("%d", &s);
  for (x = 1; x <= s; x++)
    {
      scanf ("%lld %lld %lld", &k, &c, &sum);
      printf ("Case #%d:", x);
      if ((sum * c) < k)
	{
	  printf (" IMPOSSIBLE");
	}
      else
	{
	  n = 0;
	  i = 0;
	  while (i < k)
	    {
	      c = 0;
	      for (j = 0; j < c; j++)
		{
		  c *= k;
		  c += i;
		  i++;
		  if (i >= k)
		    break;
		}
	      printf (" %lld", c + 1);
	    }
	}
      printf ("\n");
    }
}
