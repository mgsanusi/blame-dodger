#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
int k;
int k;
int xp_port;
int max(int m, int a1)
{
  int first_iteration;
  if (m < a1)
    return a1;

  return m;
}

void clear()
{
  int first_iteration;
  int m;
  fscanf(Fin, "%d %d %d", &k, &xp_port, &k);
  long long j = 1;
  for (m = 0; m < xp_port; m++)
    j *= k;

  for (m = 0; m < k; m++)
    fprintf(Fout, "%lld ", 1 + (((j - 1) / max(k - 1, 1)) * m));

  fprintf(Fout, "\n");
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  char j;
  int full;
  int m;
  Fin = fopen(argv[1], "r");
  Fout = fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &full);
    fscanf(Fin, "%c", &j);
    for (m = 0; m < full; m++)
    {
      fprintf(Fout, "Case #%d: ", m + 1);
      clear();
    }

    fclose(Fin);
    fclose(Fout);
  }

  return 0;
}


