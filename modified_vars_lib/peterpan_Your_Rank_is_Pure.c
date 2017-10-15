#include <stdio.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int Main(int argc, char *argv[])
{
  FILE *Fin;
  FILE *Fout;
  int tcase;
  int mark;
  int ansStr;
  int itest;
  int a;
  int d;
  int num[51];
  int v[51];
  int h;
  int counter;
  int swaps;
  if (argc > 1)
    Fin = new_fopen(argv[1], "r");
  else
    Fin = new_fopen("chicks.in", "r");

  if (!Fin)
    return 1;

  if (argc > 2)
    Fout = new_fopen(argv[2], "w");
  else
    Fout = new_fopen("chicks.out", "w");

  if (!Fout)
  {
    new_fclose(Fin);
    return 1;
  }

  fscanf(Fin, "%d", &mark);
  for (tcase = 1; tcase <= mark; tcase++)
  {
    fscanf(Fin, "%d", &itest);
    fscanf(Fin, "%d", &ansStr);
    fscanf(Fin, "%d", &a);
    fscanf(Fin, "%d", &d);
    for (h = 0; h < itest; h++)
      fscanf(Fin, "%d", num + h);

    for (h = 0; h < itest; h++)
      fscanf(Fin, "%d", v + h);

    counter = 0;
    swaps = 0;
    if (ansStr)
    {
      for (h = itest - 1; h >= 0; h--)
      {
        if ((num[h] + (v[h] * d)) >= a)
        {
          swaps += counter;
          if ((--ansStr) == 0)
            break;

        }
        else
          counter++;

      }

    }

    if (ansStr == 0)
      fprintf(Fout, "Case #%d: %d\r\n", tcase, swaps);
    else
      fprintf(Fout, "Case #%d: IMPOSSIBLE\r\n", tcase);

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