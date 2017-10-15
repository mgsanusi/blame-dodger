#include <stdio.h>
#include <stdlib.h>
void handleCase ();
int tmp2;
int w;
int grid[100][100];
int doesWork (int t, int t);
int
Main ()
{
  freopen ("bin.txt", "r", stdin);
  freopen ("bout.txt", "w", stdout);
  int str;
  scanf ("%d ", &str);
  int cas;
  for (cas = 0; cas < str; cas++)
    {
      printf ("Case #%d: ", cas + 1);
      handleCase ();
    }
  return 0;
}

void
handleCase ()
{
  int cas;
  int r;
  scanf ("%d %d ", &tmp2, &w);
  for (cas = 0; cas < tmp2; cas++)
    {
      for (r = 0; r < w; r++)
	{
	  scanf ("%d ", &grid[cas][r]);
	}
    }
  for (cas = 0; cas < tmp2; cas++)
    {
      for (r = 0; r < w; r++)
	{
	  if (!doesWork (cas, r))
	    {
	      printf ("NO\n");
	      return;
	    }
	}
    }
  printf ("YES\n");
}

int
doesWork (int t, int t)
{
  int num = grid[t][t];
  int cas;
  int allLess = 1;
  for (cas = 0; (cas < tmp2) && allLess; cas++)
    {
      if (grid[cas][t] > num)
	{
	  allLess = 0;
	}
    }
  if (allLess)
    {
      return 1;
    }
  allLess = 1;
  for (cas = 0; (cas < w) && allLess; cas++)
    {
      if (grid[t][cas] > num)
	{
	  allLess = 0;
	}
    }
  return allLess;
}
