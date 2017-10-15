#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int new_fgetc(FILE *stream);
int main()
{
  int first_iteration;
  FILE *fp;
  FILE *fo;
  fo = new_fopen("outputa.txt", "w");
  fp = new_fopen("inputa.in", "r");
  int T;
  int i;
  int j;
  int first;
  int last;
  int kl;
  char an[3002];
  char c;
  fscanf(fp, "%d", &T);
  if (new_fgetc(fp) == '\n')
  {
    printf("hi");
  }

  for (kl = 1; kl <= T; kl++)
  {
    fprintf(fo, "Case #");
    fprintf(fo, "%d", kl);
    fprintf(fo, ":");
    fprintf(fo, " ");
    first = 0;
    last = 0;
    c = new_fgetc(fp);
    while (c != '\n')
    {
      if (first == 0)
      {
        an[1001] = c;
        first = 1001;
        last = 1001;
      }
      else
      {
        if (c >= an[first])
        {
          first = first - 1;
          an[first] = c;
        }
        else
        {
          last = last + 1;
          an[last] = c;
        }

      }

      c = new_fgetc(fp);
    }

    for (i = first; i <= last; i++)
    {
      fprintf(fo, "%c", an[i]);
    }

    fprintf(fo, "\n");
  }

  return 1;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int new_fgetc(FILE *stream)
{
  int first_iteration;
  return fgetc(stream);
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}


