#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int Main()
{
  FILE *n;
  FILE *fo;
  n = fopen("B-small-attempt0.in", "r");
  fo = fopen("outputa.txt", "w");
  long long int ntest;
  long long int pw;
  long long int c;
  long long int wp;
  long long int arr[101][101];
  long long int k;
  long long int e;
  long long int tada;
  long long int minus;
  long long int max;
  fscanf(n, "%lld", &c);
  for (wp = 1; wp <= c; wp++)
  {
    fprintf(fo, "Case #");
    fprintf(fo, "%lld", wp);
    fprintf(fo, ":");
    fprintf(fo, " ");
    fscanf(n, "%lld", &k);
    fscanf(n, "%lld", &e);
    max = ((long long int) pow(2, k - 2)) + 0.5;
    if (e > max)
    {
      fprintf(fo, "IMPOSSIBLE");
      fprintf(fo, "\n");
    }
    else
    {
      fprintf(fo, "POSSIBLE");
      fprintf(fo, "\n");
      for (ntest = 1; ntest <= k; ntest++)
      {
        for (pw = 1; pw <= k; pw++)
        {
          arr[ntest][pw] = 0;
        }

      }

      for (ntest = 1; ntest <= k; ntest++)
      {
        for (pw = ntest + 1; pw <= k; pw++)
        {
          arr[ntest][pw] = 1;
        }

      }

      minus = max - e;
      pw = k - 3;
      while (minus > 0)
      {
        tada = ((long long int) pow(2, pw)) + 0.5;
        if (tada <= minus)
        {
          minus = minus - tada;
          arr[1][(k - 1) - pw] = 0;
        }

        pw = pw - 1;
      }

      for (ntest = 1; ntest <= k; ntest++)
      {
        for (pw = 1; pw <= k; pw++)
        {
          fprintf(fo, "%lld", arr[ntest][pw]);
        }

        fprintf(fo, "\n");
      }

    }

  }

  return 0;
}


