#include <stdio.h>
#include <string.h>
FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream);

int Main()
{
  FILE *Fin = new_fopen("base.in", "r");
  FILE *Fout = new_fopen("base.out", "w");
  int size;
  int ctx;
  int j;
  int k;
  int temp2_index;
  int test;
  int r;
  char input[80];
  int c[300];
  int r[300];
  long res;
  long x;
  fscanf(Fin, "%d\n", &test);
  for (temp2_index = 1; temp2_index <= test; temp2_index++)
  {
    new_fgets(input, 70, Fin);
    for (ctx = 0; ctx < 300; ctx++)
      r[ctx] = -1;

    r = 0;
    res = 0;
    x = 1;
    size = strlen(input) - 1;
    r[input[0]] = 1;
    for (ctx = 1; ctx < size; ctx++)
      if (r[input[ctx]] == (-1))
    {
      r[input[ctx]] = r;
      r++;
      if (r == 1)
        r++;

    }


    if (r == 0)
      r = 2;

    for (ctx = size - 1; ctx >= 0; ctx--)
    {
      res += x * r[input[ctx]];
      if (ctx > 0)
        x *= r;

    }

    fprintf(Fout, "Case #%d: %d\n", temp2_index, res);
  }

  return 0;
}



FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}