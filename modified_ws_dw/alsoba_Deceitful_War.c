#include <stdio.h>
#include <stdlib.h>
int A;
int B;
int K;
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
  fin = fopen(argv[1], "r");
  fout = fopen("out", "w");
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

    fclose(fin);
    fclose(fout);
  }

  return 0;
}


