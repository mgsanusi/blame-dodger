#include <stdio.h>
#include <stdlib.h>
int c;
int p;
int c;
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int Main(int argc, char *argv[])
{
  int first_iteration;
  FILE *Fin;
  FILE *Fout;
  char ans2;
  int total;
  int vz;
  int i_t;
  int x;
  int sum;
  Fin = new_fopen(argv[1], "r");
  Fout = new_fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &total);
    fscanf(Fin, "%c", &ans2);
    for (vz = 0; vz < total; vz++)
    {
      fscanf(Fin, "%d", &c);
      fscanf(Fin, "%d", &p);
      fscanf(Fin, "%d", &c);
      sum = 0;
      for (x = 0; x < c; x++)
      {
        for (i_t = 0; i_t < p; i_t++)
        {
          if ((i_t & x) < c)
          {
            sum++;
          }

        }

      }

      fprintf(Fout, "Case #%d: %d\n", vz + 1, sum);
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