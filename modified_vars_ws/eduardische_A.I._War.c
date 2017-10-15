#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int
Main ()
{
  static char xpReply[1000005];
  memset (xpReply, 1, sizeof (xpReply));
  int exp;
  int first;
  xpReply[0] = 0;
  xpReply[1] = 0;
  for (exp = 2; (exp * exp) <= 1000000; exp++)
    {
      if (xpReply[exp])
	{
	  for (first = 2 * exp; first <= 1000000; first += exp)
	    xpReply[first] = 0;
	}
    }
  int t;
  int index;
  scanf ("%d", &t);
  for (index = 0; index < t; index++)
    {
      long long int n;
      scanf ("%I64i", &n);
      if (n == 1LL)
	{
	  printf ("Case #%d: 0\n", index + 1);
	  continue;
	}
      long long int max = 1LL;
      long long int min = 0LL;
      long long int no;
      for (exp = 1; (((long long int) exp) * ((long long int) exp)) <= n;
	   exp++)
	{
	  if (xpReply[exp])
	    {
	      min++;
	      no = (long long int) exp;
	      int count = 1;
	      while ((no * ((long long int) exp)) <= n)
		{
		  no *= (long long int) exp;
		  count++;
		}
	      max += (long long int) count;
	    }
	}
      printf ("Case #%d: %I64i\n", index + 1, max - min);
    }
  return 0;
}
