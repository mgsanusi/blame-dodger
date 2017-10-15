#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
int t2[2501];
int sol[50];
int best;
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

void solve()
{
  int num_used;
  int j;
  int k;
  int fp_i;
  fscanf(Fin, "%d", &best);
  for (num_used = 0; num_used < 2501; num_used++)
    t2[num_used] = 0;

  for (num_used = 0; num_used < (((2 * best) - 1) * best); num_used++)
  {
    fscanf(Fin, "%d", &fp_i);
    t2[fp_i]++;
  }

  k = 0;
  for (num_used = 0; num_used < 2501; num_used++)
  {
    if ((t2[num_used] % 2) != 0)
    {
      sol[k] = num_used;
      k++;
    }

  }

  for (num_used = 0; num_used < k; num_used++)
    for (j = num_used + 1; j < k; j++)
    if (sol[j] < sol[num_used])
  {
    int t = sol[num_used];
    sol[num_used] = sol[j];
    sol[j] = t;
  }



  if (k != best)
    printf("ERROR\n");

  for (num_used = 0; num_used < best; num_used++)
  {
    fprintf(Fout, "%d ", sol[num_used]);
  }

  fprintf(Fout, "\n");
}

int Main(int argc, char *argv[])
{
  char n;
  int full;
  int num_used;
  Fin = new_fopen(argv[1], "r");
  Fout = new_fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &full);
    fscanf(Fin, "%c", &n);
    for (num_used = 0; num_used < full; num_used++)
    {
      fprintf(Fout, "Case #%d: ", num_used + 1);
      solve();
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