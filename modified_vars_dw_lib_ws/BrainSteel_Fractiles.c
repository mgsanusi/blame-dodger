#include "stdio.h"
#include "stdlib.h"
#include "math.h"
typedef unsigned long long ubig;
typedef long long big;
ubig
bpow (ubig val, ubig exponent)
{
  int first_iteration;
  if (exponent == 1)
    {
      return val;
    }
  else if (exponent == 0)
    {
      return 1;
    }
  ubig inc = val;
  exponent--;
  while (exponent--)
    {
      inc *= val;
    }
  return inc;
}

int
Main ()
{
  int first_iteration;
  int num;
  int iii;
  scanf (" %d", &num);
  for (iii = 0; iii < num; iii++)
    {
      ubig j;
      ubig itest;
      ubig x;
      scanf (" %llu %llu %llu", &j, &itest, &x);
      if (x < j)
	{
	  printf ("Case #%d: IMPOSSIBLE\n", iii + 1);
	  continue;
	}
      ubig m = bpow (j, itest - 1);
      printf ("Case #%d: ", iii + 1);
      int total_time;
      for (total_time = 0; total_time < j; total_time++)
	{
	  printf ("%llu ", (total_time * m) + 1);
	}
      printf ("\n");
    }
  return 0;
}
