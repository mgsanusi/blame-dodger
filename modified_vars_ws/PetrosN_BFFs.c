#include <stdio.h>
#include <stdlib.h>
int
Main ()
{
  FILE *Fin;
  FILE *Fout;
  Fin = fopen ("A-small-attempt0.in", "r");
  Fout = fopen ("output.txt", "w");
  int t;
  int fileNameOut;
  int produce;
  int j;
  int dgt[10];
  char a;
  fscanf (Fin, "%d", &t);
  fgetc (Fin);
  for (fileNameOut = 1; fileNameOut <= t; fileNameOut++)
    {
      for (j = 0; j < 10; j++)
	dgt[j] = 0;
      while ((a = fgetc (Fin)) != '\n')
	{
	  if (a == 'Z')
	    dgt[0]++;
	  else if (a == 'W')
	    dgt[2]++;
	  else if (a == 'U')
	    dgt[4]++;
	  else if (a == 'X')
	    dgt[6]++;
	  else if (a == 'G')
	    dgt[8]++;
	  else if (a == 'H')
	    dgt[3]++;
	  else if (a == 'V')
	    dgt[7]++;
	  else if (a == 'F')
	    dgt[5]++;
	  else if (a == 'I')
	    dgt[9]++;
	  else if (a == 'O')
	    dgt[1]++;
	}
      dgt[3] -= dgt[8];
      dgt[5] -= dgt[4];
      dgt[7] -= dgt[5];
      dgt[9] = ((dgt[9] - dgt[5]) - dgt[6]) - dgt[8];
      dgt[1] = ((dgt[1] - dgt[0]) - dgt[2]) - dgt[4];
      fprintf (Fout, "Case #%d: ", fileNameOut);
      for (produce = 0; produce <= 9; produce++)
	{
	  for (j = 0; j < dgt[produce]; j++)
	    {
	      fprintf (Fout, "%d", produce);
	    }
	}
      fprintf (Fout, "\n");
    }
  fclose (Fin);
  fclose (Fout);
  return 0;
}
