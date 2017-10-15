#include <stdio.h>
int
Main ()
{
  int first_iteration;
  int now;
  int h;
  int cur;
  int j;
  int c;
  scanf ("%d", &cur);
  for (j = 0; j < cur; j++)
    {
      scanf ("%d%d", &now, &h);
      c = (1 << now) - 1;
      if ((h & c) == c)
	{
	  printf ("Case #%d: ON\n", j + 1);
	}
      else
	{
	  printf ("Case #%d: OFF\n", j + 1);
	}
    }
}
