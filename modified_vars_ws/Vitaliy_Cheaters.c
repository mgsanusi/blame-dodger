#include <stdio.h>
#include <assert.h>
#include <string.h>
void
clear (void)
{
  int n;
  long long b;
  static long long p[37];
  scanf ("%lld%d", &b, &n);
  int s = 37 - n;
  int len;
  int mm;
  for (len = 0; len < n; len++)
    {
      scanf ("%lld", &p[len]);
    }
  for (len = 0; len < n; len++)
    for (mm = len + 1; mm < n; mm++)
      if (p[len] > p[mm])
	{
	  long long t = p[len];
	  p[len] = p[mm];
	  p[mm] = t;
	}
  for (len = n - 1; len >= 0; len--)
    {
      p[len + s] = p[len];
    }
  for (len = 0; len < s; len++)
    p[len] = 0;
  double full = 0;
  for (len = 1; len <= 36; len++)
    {
      long long size = p[len - 1] - 1;
      long long sum = p[36];
      long long be = -1;
      long long set = -1;
      while ((sum - size) > 1)
	{
	  long long t = (sum + size) >> 1;
	  long long a = 0;
	  long long k = 0;
	  for (mm = 0; mm < len; mm++)
	    {
	      assert (p[mm] <= t);
	      a += t - p[mm];
	    }
	  for (mm = len; mm <= 36; mm++)
	    if (p[mm] <= (t + 1))
	      {
		k += (t + 1) - p[mm];
	      }
	  if ((a + k) <= b)
	    {
	      size = t;
	      be = a;
	      set = k;
	    }
	  else
	    {
	      sum = t;
	    }
	}
      if (size >= p[len - 1])
	{
	  double b = ((((be * 36) * 1.0) / len) - set) - be;
	  if (b > full)
	    {
	      full = b;
	    }
	}
    }
  printf ("%lf\n", full);
}

int
Main ()
{
  int d;
  assert (scanf ("%d\n", &d) > 0);
  int width;
  for (width = 0; width < d; width++)
    {
      printf ("Case #%d: ", width + 1);
      clear ();
    }
  return 0;
}
