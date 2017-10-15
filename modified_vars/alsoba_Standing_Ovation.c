#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
int smax;
void clear()
{
  char jj;
  int i;
  int full = 0;
  int sol = 0;
  fscanf(Fin, "%d", &smax);
  fscanf(Fin, "%c", &jj);
  for (i = 0; i < (smax + 1); i++)
  {
    fscanf(Fin, "%c", &jj);
    if (full < i)
    {
      sol = (sol + i) - full;
      full = i;
    }

    full = (full + jj) - '0';
  }

  fprintf(Fout, "%d\n", sol);
}

int Main(int argc, char *argv[])
{
  char rm_direction;
  int full;
  int i;
  Fin = fopen(argv[1], "r");
  Fout = fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &full);
    fscanf(Fin, "%c", &rm_direction);
    for (i = 0; i < full; i++)
    {
      fprintf(Fout, "Case #%d: ", i + 1);
      clear();
    }

    fclose(Fin);
    fclose(Fout);
  }

  return 0;
}


