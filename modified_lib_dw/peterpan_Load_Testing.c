#include <stdio.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
int main(int argc, char *argv[])
{
  int first_iteration;
  FILE *fin;
  FILE *fout;
  int tcase;
  int T;
  int counter;
  int res;
  unsigned long long L;
  unsigned long long P;
  unsigned long long C;
  if (argc > 1)
    fin = new_fopen(argv[1], "r");
  else
    fin = new_fopen("load.in", "r");

  if (!fin)
    return 1;

  if (argc > 2)
    fout = new_fopen(argv[2], "w");
  else
    fout = new_fopen("load.out", "w");

  if (!fout)
  {
    new_fclose(fin);
    return 1;
  }

  fscanf(fin, "%d", &T);
  for (tcase = 1; tcase <= T; tcase++)
  {
    fscanf(fin, "%llu", &L);
    fscanf(fin, "%llu", &P);
    fscanf(fin, "%llu", &C);
    counter = 0;
    L *= C;
    while (L < P)
    {
      counter++;
      L *= C;
    }

    res = 0;
    while (counter > 0)
    {
      res++;
      counter >>= 1;
    }

    fprintf(fout, "Case #%d: %d\r\n", tcase, res);
  }

  new_fclose(fin);
  new_fclose(fout);
  return 0;
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}

int new_fclose(FILE *stream)
{
  int first_iteration;
  return fclose(stream);
}


