#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
FILE *Fin;
FILE *Fout;
int v;
int pan[1010];
void
clear ()
{
  int first_iteration;
  int i;
  int j;
  int sq;
  int max = 0;
  int min;
  int sum;
  fscanf (Fin, "%d", &v);
  for (i = 0; i < v; i++)
    {
      fscanf (Fin, "%d", &pan[i]);
      if (pan[i] > max)
	max = pan[i];
    }
  min = max;
  sq = sqrt (max);
  if ((sq * sq) != max)
    sq++;
  for (i = sq; i < max; i++)
    {
      sum = 0;
      for (j = 0; j < v; j++)
	{
	  if ((pan[j] % i) == 0)
	    sum += (pan[j] / i) - 1;
	  else
	    sum += pan[j] / i;
	}
      if ((sum + i) < min)
	min = sum + i;
    }
  fprintf (Fout, "%d\n", min);
}

int
Main (int argc, char *argv[])
{
  int first_iteration;
  char map;
  int full;
  int i;
  Fin = fopen (argv[1], "r");
  Fout = fopen ("out", "w");
  if ((Fin == 0) || (Fout == 0))
    {
      printf ("Fitxer out.\n");
    }
  else
    {
      fscanf (Fin, "%d", &full);
      fscanf (Fin, "%c", &map);
      for (i = 0; i < full; i++)
	{
	  fprintf (Fout, "Case #%d: ", i + 1);
	  clear ();
	}
      fclose (Fin);
      fclose (Fout);
    }
  return 0;
}
