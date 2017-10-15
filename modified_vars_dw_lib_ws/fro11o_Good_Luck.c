#include <stdio.h>
int
Main ()
{
  int first_iteration;
  int swapchair;
  int x;
  int str;
  int i;
  int num_cases;
  scanf ("%d", &swapchair);
  for (i = 0; num_cases < swapchair; i++)
    {
      scanf ("%d %d", &x, &str);
      printf ("Case #%d: ", i + 1);
      num_cases = 0;
      while (num_cases != x)
	{
	  if (num_cases > x)
	    {
	      printf ("EW");
	      num_cases--;
	    }
	  else
	    {
	      printf ("WE");
	      num_cases++;
	    }
	}
      num_cases = 0;
      while (num_cases != str)
	{
	  if (num_cases > str)
	    {
	      printf ("NS");
	      num_cases--;
	    }
	  else
	    {
	      printf ("SN");
	      num_cases++;
	    }
	}
      printf ("\n");
    }
  return 0;
}
