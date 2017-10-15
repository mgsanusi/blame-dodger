#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
FILE * new_fopen(const char *filename, const char *mode);

double new_pow(double base, double exponent);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int Main()
{
  FILE *a;
  FILE *n;
  a = new_fopen("inputa.in", "r");
  n = new_fopen("outputa.txt", "w");
  int on;
  int y;
  int n;
  int io;
  int arr[60][60];
  int x;
  int m;
  int tada;
  int minus;
  int max;
  fscanf(a, "%d", &n);
  for (io = 1; io <= n; io++)
  {
    fprintf(n, "Case #");
    fprintf(n, "%d", io);
    fprintf(n, ":");
    fprintf(n, " ");
    fscanf(a, "%d", &x);
    fscanf(a, "%d", &m);
    max = ((int) new_pow(2, x - 2)) + 0.5;
    if (m > max)
    {
      fprintf(n, "IMPOSSIBLE");
      fprintf(n, "\n");
    }
    else
    {
      fprintf(n, "POSSIBLE");
      fprintf(n, "\n");
      for (on = 1; on <= x; on++)
      {
        for (y = 1; y <= x; y++)
        {
          arr[on][y] = 0;
        }

      }

      for (on = 1; on <= x; on++)
      {
        for (y = on + 1; y <= x; y++)
        {
          arr[on][y] = 1;
        }

      }

      minus = max - m;
      printf("%d", minus);
      y = x - 3;
      while (minus > 0)
      {
        tada = ((int) new_pow(2, y)) + 0.5;
        if (tada <= minus)
        {
          minus = minus - tada;
          arr[1][(x - 1) - y] = 0;
        }

        y = y - 1;
      }

      for (on = 1; on <= x; on++)
      {
        for (y = 1; y <= x; y++)
        {
          fprintf(n, "%d", arr[on][y]);
        }

        fprintf(n, "\n");
      }

    }

  }

  return 1;
}



FILE * new_fopen(const char *filename, const char *mode);

double new_pow(double base, double exponent) {
  return pow(base, exponent);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}