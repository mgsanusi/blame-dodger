#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
int
Main (void)
{
  int no;
  int max;
  int options;
  long long res;
  long long r;
  long long s2;
  long long n;
  long long e;
  scanf ("%d", &no);
  for (options = 1; options <= no; ++options)
    {
      scanf ("%lld %lld", &r, &s2);
      for (res = 0, e = 0; e <= s2; ++res)
	{
	  e += (2 * (r + (res * 2))) + 1;
	}
      res--;
      printf ("Case #%d: %lld\n", options, res);
    }
  return 0;
}
