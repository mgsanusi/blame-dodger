#include <stdio.h>
int
Main (void)
{
  int first_iteration;
  int m;
  int is_win;
  scanf ("%d", &is_win);
  for (m = 1; m <= is_win; m++)
    {
      int i;
      int g;
      int ret = 0;
      scanf ("%d", &g);
      for (i = 1; i <= g; i++)
	{
	  int x;
	  scanf ("%d", &x);
	  if (i != x)
	    ret++;
	}
      printf ("Case #%d: %d\n", m, ret);
    }
  return 0;
}
