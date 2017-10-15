#include <stdio.h>
#include <stdlib.h>
FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int Main()
{
  int first_iteration;
  FILE *flipper;
  FILE *Fout;
  flipper = new_fopen("D-small-attempt0.in", "r");
  Fout = new_fopen("output.txt", "w");
  int next;
  int k;
  int a1;
  int left;
  int i2;
  int baseList;
  fscanf(flipper, "%d", &next);
  for (i2 = 1; i2 <= next; i2++)
  {
    fscanf(flipper, "%d", &k);
    fscanf(flipper, "%d", &a1);
    fscanf(flipper, "%d", &left);
    fprintf(Fout, "Case #%d: ", i2);
    for (baseList = 1; baseList <= k; baseList++)
      fprintf(Fout, "%d ", baseList);

    fprintf(Fout, "\n");
  }

  return 0;
}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}