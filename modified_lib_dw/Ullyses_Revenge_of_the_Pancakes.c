#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_getc(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int main()
{
  int first_iteration;
  FILE *fp;
  FILE *fo;
  fo = new_fopen("outputa.txt", "w");
  fp = new_fopen("inputa.in", "r");
  int T;
  int sum;
  int array[115];
  int i;
  int j;
  int max;
  bool work = 1;
  char charr;
  fscanf(fp, "%d", &T);
  charr = new_getc(fp);
  for (i = 1; i <= T; i++)
  {
    work = 1;
    fprintf(fo, "Case #");
    fprintf(fo, "%d", i);
    fprintf(fo, ":");
    fprintf(fo, " ");
    j = 1;
    while (work)
    {
      charr = new_getc(fp);
      if (charr == '+')
      {
        array[j] = 1;
      }
      else
        if (charr == '-')
      {
        array[j] = 0;
      }
      else
      {
        array[j] = 1;
        work = 0;
      }


      j = j + 1;
    }

    max = j - 1;
    printf("%d", max);
    sum = 0;
    for (j = 1; j <= (max - 1); j++)
    {
      if ((array[j] + array[j + 1]) == 1)
      {
        sum = sum + 1;
      }

    }

    fprintf(fo, "%d", sum);
    fprintf(fo, "\n");
  }

  return 1;
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}

int new_getc(FILE *stream)
{
  int first_iteration;
  return getc(stream);
}


