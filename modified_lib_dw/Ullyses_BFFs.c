#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int main()
{
  int first_iteration;
  FILE *fp;
  FILE *fo;
  fp = new_fopen("inputa.in", "r");
  fo = new_fopen("outputa.txt", "w");
  int i;
  int j;
  int T;
  int io;
  int n;
  int array[50];
  int imax;
  int max;
  int length;
  int temp;
  int left[5];
  char c;
  bool work;
  fscanf(fp, "%d", &T);
  for (io = 1; io <= T; io++)
  {
    fprintf(fo, "Case #");
    fprintf(fo, "%d", io);
    fprintf(fo, ":");
    fprintf(fo, " ");
    fscanf(fp, "%d", &n);
    for (i = 1; i <= n; i++)
    {
      fscanf(fp, "%d", &array[i]);
    }

    length = n;
    work = 1;
    if (n <= 2)
    {
      work = 0;
    }

    while (work)
    {
      imax = 0;
      max = 0;
      for (i = 1; i <= n; i++)
      {
        if (array[i] >= max)
        {
          max = array[i];
          imax = i;
        }

      }

      if (max == 1)
      {
        length = length - 1;
      }

      if (length <= 2)
      {
        work = 0;
      }

      array[imax] = array[imax] - 1;
      fprintf(fo, "%c", ('A' + imax) - 1);
      fprintf(fo, " ");
    }

    j = 1;
    for (i = 1; i <= n; i++)
    {
      if (array[i] != 0)
      {
        left[j] = i;
        j = j + 1;
      }

    }

    if (array[left[2]] > array[left[1]])
    {
      temp = left[1];
      left[1] = left[2];
      left[2] = temp;
    }

    for (i = 1; i <= (array[left[1]] - array[left[2]]); i++)
    {
      fprintf(fo, "%c", ('A' + left[1]) - 1);
      fprintf(fo, " ");
    }

    for (i = 1; i <= array[left[2]]; i++)
    {
      fprintf(fo, "%c", ('A' + left[1]) - 1);
      fprintf(fo, "%c", ('A' + left[2]) - 1);
      fprintf(fo, " ");
    }

    fprintf(fo, "\n");
  }

  return 1;
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}


