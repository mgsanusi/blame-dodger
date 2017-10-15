#include <stdio.h>
#include <stdlib.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_fgetc(FILE *stream);

int Main()
{
  FILE *Fin;
  FILE *Fout;
  Fout = new_fopen("output.txt", "w");
  Fin = new_fopen("A-small-attempt0.in", "r");
  int length;
  int length;
  int first;
  int last;
  int i;
  char j;
  char io[2001];
  fscanf(Fin, "%d", &length);
  j = new_fgetc(Fin);
  for (length = 1; length <= length; length++)
  {
    first = 1000;
    last = 1000;
    j = new_fgetc(Fin);
    io[1000] = j;
    while (((j = new_fgetc(Fin)) != '\n') && (j != EOF))
    {
      if (j >= io[first])
      {
        io[first - 1] = j;
        first--;
      }
      else
      {
        io[last + 1] = j;
        last++;
      }

    }

    fprintf(Fout, "Case #%d: ", length);
    for (i = first; i <= last; i++)
    {
      fprintf(Fout, "%c", io[i]);
    }

    fprintf(Fout, "\n");
  }

  new_fclose(Fin);
  new_fclose(Fout);
  return 0;
}



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_fgetc(FILE *stream) {
  return fgetc(stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}