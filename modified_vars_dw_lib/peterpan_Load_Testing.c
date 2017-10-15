#include <stdio.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int Main(int argc, char *argv[])
{
  int first_iteration;
  FILE *Fin;
  FILE *Fout;
  int tcase;
  int tmp;
  int counter;
  int answer;
  unsigned long long i;
  unsigned long long t;
  unsigned long long right;
  if (argc > 1)
    Fin = new_fopen(argv[1], "r");
  else
    Fin = new_fopen("load.in", "r");

  if (!Fin)
    return 1;

  if (argc > 2)
    Fout = new_fopen(argv[2], "w");
  else
    Fout = new_fopen("load.out", "w");

  if (!Fout)
  {
    new_fclose(Fin);
    return 1;
  }

  fscanf(Fin, "%d", &tmp);
  for (tcase = 1; tcase <= tmp; tcase++)
  {
    fscanf(Fin, "%llu", &i);
    fscanf(Fin, "%llu", &t);
    fscanf(Fin, "%llu", &right);
    counter = 0;
    i *= right;
    while (i < t)
    {
      counter++;
      i *= right;
    }

    answer = 0;
    while (counter > 0)
    {
      answer++;
      counter >>= 1;
    }

    fprintf(Fout, "Case #%d: %d\r\n", tcase, answer);
  }

  new_fclose(Fin);
  new_fclose(Fout);
  return 0;
}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}