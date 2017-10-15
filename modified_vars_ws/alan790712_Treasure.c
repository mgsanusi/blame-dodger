#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int n;
long long int size;
int
Main ()
{
  int t;
  int b;
  int min;
  long long int j;
  long long int c;
  long long int test;
  long long int answer;
  long long int tmp[2];
  int key;
  scanf ("%d", &t);
  for (b = 1; b <= t; ++b)
    {
      scanf ("%lld %lld", &size, &n);
      printf ("Case #%d: ", b);
      j = 0, c = 1000000000LL;
      answer = -1;
      while (j <= c)
	{
	  key = 1;
	  test = (j + c) / 2LL;
	  tmp[0] = ((2 * test) - 1) * test;
	  if (tmp[0] > n)
	    key = 0;
	  tmp[1] = (2 * test) * size;
	  if (tmp[1] > n)
	    key = 0;
	  if ((tmp[0] + tmp[1]) > n)
	    key = 0;
	  if (key)
	    {
	      if (test > answer)
		answer = test;
	      j = test + 1;
	    }
	  else
	    {
	      c = test - 1;
	    }
	}
      printf ("%lld\n", answer);
    }
  return 0;
}
