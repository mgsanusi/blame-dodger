#include <stdio.h>
#include <stdlib.h>
int
Main ()
{
  int fp_o;
  int t;
  int ans;
  int p1;
  char side[100];
  scanf ("%u", &t);
  for (fp_o = 1; fp_o <= t; fp_o++)
    {
      scanf ("%s", side);
      p1 = 0;
      for (ans = 1; side[ans] != 0; ans++)
	if (side[ans - 1] != side[ans])
	  p1++;
      if (side[ans - 1] == '-')
	p1++;
      printf ("Case #%d: %d\n", fp_o, p1);
    }
}
