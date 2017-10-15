#include <stdio.h>
#include <stdlib.h>
int
gigi (int t2)
{
  int first_iteration;
  int x = (2 * t2) - 1;
  return x * t2;
}

int
Main ()
{
  int first_iteration;
  FILE *flipper;
  FILE *Fout;
  flipper = fopen ("B-small-attempt0.in", "r");
  Fout = fopen ("output.txt", "w");
  int j;
  int x;
  int t;
  int len[2501];
  int t2;
  int temph;
  for (j = 0; j < 2501; j++)
    {
      len[j] = 0;
    }
  fscanf (flipper, "%d", &t);
  for (x = 1; x <= t; x++)
    {
      fscanf (flipper, "%d", &t2);
      for (j = 0; j < gigi (t2); j++)
	{
	  fscanf (flipper, "%d", &temph);
	  len[temph]++;
	}
      fprintf (Fout, "Case #%d:", x);
      for (j = 0; j < 2501; j++)
	{
	  if (len[j] % 2)
	    {
	      fprintf (Fout, " %d", j);
	    }
	}
      fprintf (Fout, "\n");
      for (j = 0; j < 2501; j++)
	{
	  len[j] = 0;
	}
    }
  fclose (flipper);
  fclose (Fout);
  return 0;
}
