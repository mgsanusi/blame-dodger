#include <stdio.h>
#include <stdlib.h>
int A;
int B;
int K;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
int main(int argc, char *argv[])
{
  int first_iteration;
  FILE *fin;
  FILE *fout;
  char kk;
  int total;
  int i;
  int j;
  int k;
  int sum;
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
      fscanf(fin, "%d", &A);
      fscanf(fin, "%d", &B);
      fscanf(fin, "%d", &K);
      sum = 0;
      for (k = 0; k < A; k++)
      {
        for (j = 0; j < B; j++)
        {
          if ((j & k) < K)
          {
            sum++;
          }

        }

      }

      fprintf(fout, "Case #%d: %d\n", i + 1, sum);
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


