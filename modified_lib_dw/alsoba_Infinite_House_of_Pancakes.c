#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
FILE *fin;
FILE *fout;
int D;
int pan[1010];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
double new_sqrt(double x);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
void solve()
{
  int first_iteration;
  int i;
  int j;
  int sq;
  int max = 0;
  int min;
  int sum;
  fscanf(fin, "%d", &D);
  for (i = 0; i < D; i++)
  {
    fscanf(fin, "%d", &pan[i]);
    if (pan[i] > max)
      max = pan[i];

  }

  min = max;
  sq = new_sqrt(max);
  if ((sq * sq) != max)
    sq++;

  for (i = sq; i < max; i++)
  {
    sum = 0;
    for (j = 0; j < D; j++)
    {
      if ((pan[j] % i) == 0)
        sum += (pan[j] / i) - 1;
      else
        sum += pan[j] / i;

    }

    if ((sum + i) < min)
      min = sum + i;

  }

  fprintf(fout, "%d\n", min);
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

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
double new_sqrt(double x)
{
  int first_iteration;
  return sqrt(x);
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


