#include <stdio.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int Main(int argc, char *argv[])
{
  FILE *Fin;
  FILE *Fout;
  int tcase;
  int i1;
  int cc;
  int counter;
  int t;
  int eU;
  int a[1000];
  int t[1000];
  if (argc > 1)
    Fin = new_fopen(argv[1], "r");
  else
    Fin = new_fopen("rope.in", "r");

  if (!Fin)
    return 1;

  if (argc > 2)
    Fout = new_fopen(argv[2], "w");
  else
    Fout = new_fopen("rope.out", "w");

  if (!Fout)
  {
    new_fclose(Fin);
    return 1;
  }

  fscanf(Fin, "%d", &i1);
  for (tcase = 1; tcase <= i1; tcase++)
  {
    fscanf(Fin, "%d", &cc);
    for (t = 0; t < cc; t++)
    {
      fscanf(Fin, "%d", a + t);
      fscanf(Fin, "%d", t + t);
    }

    counter = 0;
    for (t = 0; t < cc; t++)
    {
      for (eU = t + 1; eU < cc; eU++)
      {
        if (((a[t] > a[eU]) && (t[t] < t[eU])) || ((a[t] < a[eU]) && (t[t] > t[eU])))
          counter++;

      }

    }

    fprintf(Fout, "Case #%d: %d\r\n", tcase, counter);
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