#include <stdio.h>
int
Main ()
{
  int n;
  int poss[4];
  int row;
  int dump;
  int result;
  scanf ("%d", &n);
  for (int t = 1; t <= n; t++)
    {
      scanf ("%d", &row);
      for (int depT = 4; depT < (row * 4); depT++)
	{
	  scanf ("%d", &dump);
	}
      for (int depT = 0; depT < 4; depT++)
	{
	  scanf ("%d", &poss[depT]);
	}
      for (int depT = (row + 1) * 4; depT < 20; depT++)
	{
	  scanf ("%d", &dump);
	}
      scanf ("%d", &row);
      for (int depT = 4; depT < (row * 4); depT++)
	{
	  scanf ("%d", &dump);
	}
      result = 0;
      for (int depT = 0; depT < 4; depT++)
	{
	  scanf ("%d", &dump);
	  for (int n = 0; n < 4; n++)
	    {
	      if (poss[n] == dump)
		{
		  if (result)
		    {
		      result = -1;
		    }
		  else
		    {
		      result = dump;
		    }
		}
	    }
	}
      for (int depT = (row + 1) * 4; depT < 20; depT++)
	{
	  scanf ("%d", &dump);
	}
      if (result == (-1))
	{
	  printf ("Case #%d: Bad magician!\n", t);
	}
      else if (result)
	{
	  printf ("Case #%d: %d\n", t, result);
	}
      else
	{
	  printf ("Case #%d: Volunteer cheated!\n", t);
	}
    }
}
