#include <stdio.h>
#include <stdlib.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fgetc(FILE *stream);

int func(int first, int last, int p)
{
  if ((first == (-1)) && (last == (-1)))
    return (2 * p) + 1;
  else
    if ((first == (-1)) && (last == 1))
    return (2 * p) - 1;
  else
    if ((first == 1) && (last == 1))
    return (2 * p) - 2;
  else
    if ((first == 1) && (last == (-1)))
    return 2 * p;
  else
    return 0;




}

int Main()
{
  FILE *Fin;
  FILE *Fout;
  Fin = new_fopen("B-small-attempt0.in", "r");
  Fout = new_fopen("output.txt", "w");
  int a;
  int v;
  int first;
  int last;
  int plus;
  int ans;
  char tmp;
  char cprev;
  fscanf(Fin, "%d", &a);
  new_fgetc(Fin);
  for (v = 1; v <= a; v++)
  {
    plus = 0;
    cprev = new_fgetc(Fin);
    if (cprev == '+')
    {
      first = 1;
      plus++;
    }
    else
      first = -1;

    while (((tmp = new_fgetc(Fin)) != '\n') && (tmp != EOF))
    {
      if (tmp == cprev)
        continue;
      else
        if (tmp == '+')
        plus++;


      cprev = tmp;
    }

    if (cprev == '-')
      last = -1;
    else
      last = 1;

    ans = func(first, last, plus);
    fprintf(Fout, "Case #%d: %d \n", v, ans);
  }

  new_fclose(Fin);
  new_fclose(Fout);
  return 0;
}



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fgetc(FILE *stream) {
  return fgetc(stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}