#include <stdio.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream);

void llegeix(FILE *Fin, int *value)
{
  int first_iteration;
  int row;
  int y;
  char c = 0;
  char aux[20];
  fscanf(Fin, "%d", &row);
  fscanf(Fin, "%c", &c);
  for (y = 1; y < row; y++)
  {
    new_fgets(aux, 20, Fin);
  }

  fscanf(Fin, "%d", &value[0]);
  fscanf(Fin, "%d", &value[1]);
  fscanf(Fin, "%d", &value[2]);
  fscanf(Fin, "%d", &value[3]);
  fscanf(Fin, "%c", &c);
  for (; y < 4; y++)
  {
    new_fgets(aux, 20, Fin);
  }

}

int Main(int argc, char *argv[])
{
  int first_iteration;
  FILE *Fin;
  FILE *Fout;
  char c = 0;
  int first[4];
  int second[4];
  int total;
  int g;
  int j;
  int match;
  int num;
  Fin = new_fopen(argv[1], "r");
  Fout = new_fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &total);
    fscanf(Fin, "%c", &c);
    for (g = 0; g < total; g++)
    {
      match = 0;
      llegeix(Fin, first);
      llegeix(Fin, second);
      for (j = 0; j < 4; j++)
      {
        if (first[j] == second[0])
        {
          match++;
          num = first[j];
        }

        if (first[j] == second[1])
        {
          match++;
          num = first[j];
        }

        if (first[j] == second[2])
        {
          match++;
          num = first[j];
        }

        if (first[j] == second[3])
        {
          match++;
          num = first[j];
        }

      }

      fprintf(Fout, "Case #%d: ", g + 1);
      switch (match)
      {
        case 0:
          fprintf(Fout, "Volunteer cheated!\n");
          break;

        case 1:
          fprintf(Fout, "%d\n", num);
          break;

        default:
          fprintf(Fout, "Bad magician!\n");
          break;

      }

    }

    new_fclose(Fin);
    new_fclose(Fout);
  }

  return 0;
}



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}