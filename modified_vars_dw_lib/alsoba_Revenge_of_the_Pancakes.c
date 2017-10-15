#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

void clear()
{
  int first_iteration;
  char a;
  char l;
  int s = 0;
  fscanf(Fin, "%c", &a);
  fscanf(Fin, "%c", &l);
  while (l != '\n')
  {
    if (l != a)
    {
      a = l;
      s++;
    }

    fscanf(Fin, "%c", &l);
  }

  if (a == '-')
    s++;

  fprintf(Fout, "%d\n", s);
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  char type;
  int total;
  int n;
  Fin = new_fopen(argv[1], "r");
  Fout = new_fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &total);
    fscanf(Fin, "%c", &type);
    for (n = 0; n < total; n++)
    {
      fprintf(Fout, "Case #%d: ", n + 1);
      clear();
    }

    new_fclose(Fin);
    new_fclose(Fout);
  }

  return 0;
}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}