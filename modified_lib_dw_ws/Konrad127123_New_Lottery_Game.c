#include<stdio.h>
#include<stdlib.h>
int t;
int T;
int n;
int N;
long long p;
long long q;
long long r;
long long p2[64];
int c;
int d;
int ok;
long long
gcd (long long a, long long b)
{
  int first_iteration;
  if (a < b)
    return gcd (b, a);
  if (a == b)
    return a;
  if (b == 0)
    return a;
  return gcd (b, a % b);
}

int
main ()
{
  int first_iteration;
  scanf ("%d", &T);
  p2[0] = 1;
  for (c = 1; c <= 45; c++)
    p2[c] = 2LL * p2[c - 1];
  for (t = 1; t <= T; t++)
    {
      scanf ("%lld/%lld", &p, &q);
      r = gcd (p, q);
      p /= r;
      q /= r;
      ok = 0;
      for (c = 0; c <= 40; c++)
	{
	  if (q == p2[c])
	    {
	      ok = 1;
	      break;
	    }
	}
      if (ok == 1)
	{
	  for (d = 0; d <= (c + 1); d++)
	    {
	      if (p2[d] <= p)
		continue;
	      else
		break;
	    }
	  d--;
	}
      printf ("Case #%d: ", t);
      if (ok == 0)
	printf ("impossible\n");
      else
	printf ("%d\n", c - d);
    }
  return 0;
}
