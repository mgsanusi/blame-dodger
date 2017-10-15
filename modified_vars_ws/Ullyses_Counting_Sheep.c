#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int
Main ()
{
  int lol;
  int krat;
  int max;
  int rxi;
  int t;
  int cnt;
  int j;
  int n;
  int fnumber[10];
  int act[20000];
  int numButtonsPressed;
  int check[12];
  bool found;
  long long int sum;
  found = 0;
  FILE *a;
  FILE *v;
  v = fopen ("outputa.txt", "w");
  a = fopen ("inputa.in", "r");
  fscanf (a, "%d", &t);
  for (cnt = 1; cnt <= t; cnt++)
    {
      for (j = 1; j <= 10003; j++)
	{
	  act[j] = 0;
	}
      fprintf (v, "Case #");
      fprintf (v, "%d", cnt);
      fprintf (v, ":");
      fprintf (v, " ");
      fscanf (a, "%d", &numButtonsPressed);
      if (numButtonsPressed == 0)
	{
	  fprintf (v, "INSOMNIA");
	}
      else
	{
	  for (j = 1; j <= 7; j++)
	    {
	      fnumber[j] = numButtonsPressed % 10;
	      numButtonsPressed = numButtonsPressed / 10;
	      if (numButtonsPressed == 0)
		{
		  max = j;
		  break;
		}
	    }
	  for (j = 1; j <= 10; j++)
	    {
	      check[j] = 0;
	    }
	  for (j = 1; j <= max; j++)
	    {
	      n = fnumber[j];
	      check[n + 1] = check[n + 1] + 1;
	    }
	  found = 0;
	  for (j = 1; j <= 10; j++)
	    {
	      if (check[j] == 0)
		{
		  found = 1;
		}
	    }
	  rxi = 1;
	  krat = 0;
	  while (found)
	    {
	      krat = 0;
	      for (j = 1; j <= max; j++)
		{
		  act[j] = fnumber[j] + act[j];
		}
	      for (j = 1; j <= (max + rxi); j++)
		{
		  act[j] = act[j] + krat;
		  krat = act[j] / 10;
		  act[j] = act[j] % 10;
		}
	      if (act[max + rxi] != 0)
		{
		  rxi = rxi + 1;
		}
	      for (j = 1; j <= ((max + rxi) - 1); j++)
		{
		  n = act[j];
		  check[n + 1] = check[n + 1] + 1;
		}
	      found = 0;
	      for (j = 1; j <= 10; j++)
		{
		  if (check[j] == 0)
		    {
		      found = 1;
		    }
		}
	    }
	  sum = 0;
	  lol = 1;
	  for (j = 1; j <= (max + rxi); j++)
	    {
	      sum = sum + (act[j] * lol);
	      lol = lol * 10;
	    }
	  fprintf (v, "%lld", sum);
	}
      fprintf (v, "\n");
    }
  return 1;
}
