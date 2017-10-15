#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
int k;
int k;
int xp_port;
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int max(int m, int a1)
{
  if (m < a1)
    return a1;

  return m;
}

void clear()
{
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
  char j;
  int full;
  int m;
  Fin = new_fopen(argv[1], "r");
  Fout = new_fopen("out", "w");
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

    new_fclose(Fin);
    new_fclose(Fout);
  }

  return 0;
}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}