#include "stdio.h"
#include "assert.h"
#include "string.h"
int
Main ()
{
  int u;
  scanf ("%d", &u);
  int ans2;
  int temp[1 << 20];
  int t[10000];
  int dict;
  for (ans2 = 0; ans2 < u; ans2++)
    {
      int d;
      scanf ("%d", &d);
      int z = 0;
      int s = 0;
      int k = 1000000000;
      for (dict = 0; dict < d; dict++)
	{
	  scanf ("%d", &t[dict]);
	  z = z ^ t[dict];
	  s += t[dict];
	  if (k > t[dict])
	    {
	      k = t[dict];
	    }
	}
      printf ("Case #%d: ", ans2 + 1);
      if (z)
	{
	  printf ("NO\n");
	}
      else
	{
	  printf ("%d\n", s - k);
	}
    }
}
