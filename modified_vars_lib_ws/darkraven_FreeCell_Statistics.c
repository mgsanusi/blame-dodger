#include<stdio.h>
int
gcd (int fo, int b)
{
  return (fo % b) == 0 ? b : gcd (b, fo % b);
}

int
Main ()
{
  int t;
  scanf ("%d", &t);
  int r;
  for (r = 1; r <= t; r++)
    {
      int e;
      int ps;
      int fg;
      scanf ("%d%d%d", &e, &ps, &fg);
      if (ps == 0)
	{
	  if (fg != 100)
	    printf ("Case #%d: Possible\n", r);
	  else
	    printf ("Case #%d: Broken\n", r);
	  continue;
	}
      int num = 100 / gcd (100, ps);
      if (num > e)
	{
	  printf ("Case #%d: Broken\n", r);
	  continue;
	}
      if ((fg == 100) && (ps < 100))
	{
	  printf ("Case #%d: Broken\n", r);
	  continue;
	}
      if ((fg == 0) && (ps > 0))
	{
	  printf ("Case #%d: Broken\n", r);
	  continue;
	}
      printf ("Case #%d: Possible\n", r);
    }
  return 0;
}
