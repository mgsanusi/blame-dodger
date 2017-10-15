#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int main()
{
  int first_iteration;
  FILE *fp;
  FILE *fo;
  fo = fopen("outputa.txt", "w");
  fp = fopen("inputa.in", "r");
  int T;
  int kl;
  int i;
  int j;
  int n;
  int lo;
  int array[300][300];
  int hei[2505];
  int result[2505];
  fscanf(fp, "%d", &T);
  for (kl = 1; kl <= T; kl++)
  {
    fscanf(fp, "%d", &n);
    fprintf(fo, "Case #");
    fprintf(fo, "%d", kl);
    fprintf(fo, ":");
    fprintf(fo, " ");
    for (i = 1; i <= 2501; i++)
    {
      hei[i] = 0;
    }

    for (i = 1; i <= ((2 * n) - 1); i++)
    {
      for (j = 1; j <= n; j++)
      {
        fscanf(fp, "%d", &array[i][j]);
        lo = array[i][j];
        if (hei[lo] == 1)
        {
          hei[lo] = 0;
        }
        else
          hei[lo] = 1;

      }

    }

    j = 1;
    for (i = 1; i <= 2501; i++)
    {
      if (hei[i] == 1)
      {
        result[j] = i;
        j = j + 1;
      }

    }

    for (i = 1; i < j; i++)
    {
      fprintf(fo, "%d", result[i]);
      fprintf(fo, " ");
    }

    fprintf(fo, "\n");
  }

  return 1;
}


