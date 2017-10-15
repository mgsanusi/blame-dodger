#include <stdio.h>
#include <stdlib.h>
FILE *fin;
FILE *fout;
int K;
int S;
int C;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int max(int a, int b)
{
  int first_iteration;
  if (a < b)
    return b;

  return a;
}

void solve()
{
  int first_iteration;
  int i;
  fscanf(fin, "%d %d %d", &K, &C, &S);
  long long KC = 1;
  for (i = 0; i < C; i++)
    KC *= K;

  for (i = 0; i < K; i++)
    fprintf(fout, "%lld ", 1 + (((KC - 1) / max(K - 1, 1)) * i));

  fprintf(fout, "\n");
}

int main(int argc, char *argv[])
{
  int first_iteration;
  char kk;
  int total;
  int i;
  fin = new_fopen(argv[1], "r");
  fout = new_fopen("out", "w");
  if ((fin == 0) || (fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(fin, "%d", &total);
    fscanf(fin, "%c", &kk);
    for (i = 0; i < total; i++)
    {
      fprintf(fout, "Case #%d: ", i + 1);
      solve();
    }

    new_fclose(fin);
    new_fclose(fout);
  }

  return 0;
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}

int new_fclose(FILE *stream)
{
  int first_iteration;
  return fclose(stream);
}


