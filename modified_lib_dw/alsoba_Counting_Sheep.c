#include <stdio.h>
#include <stdlib.h>
FILE *fin;
FILE *fout;
long long N;
int s[10];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int end()
{
  int first_iteration;
  int i;
  for (i = 0; i < 10; i++)
  {
    if (s[i] == 0)
      return 0;

  }

  return 1;
}

void solve()
{
  int first_iteration;
  int i;
  long long M;
  fscanf(fin, "%lld", &N);
  if (N == 0)
  {
    fprintf(fout, "INSOMNIA\n");
    return;
  }

  for (i = 0; i < 10; i++)
    s[i] = 0;

  M = 0;
  first_iteration = 1;
  while ((!end()) || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    M += N;
    long long p = M;
    while (p > 0)
    {
      s[p % 10]++;
      p /= 10;
    }

  }

  fprintf(fout, "%lld\n", M);
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


