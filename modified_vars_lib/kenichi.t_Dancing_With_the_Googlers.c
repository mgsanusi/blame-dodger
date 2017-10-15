#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

void generateFilename(char *out, char *v, char *add)
{
  char *t;
  sprintf(out, "%s", v);
  for (t = (out + strlen(out)) - 1; t >= out; t--)
  {
    if ((*t) == '/')
      break;

    if ((*t) == '\\')
      break;

    if ((*t) == '.')
    {
      *t = '\0';
      break;
    }

  }

  sprintf(out + strlen(out), "%s", add);
}

void Main(int argc, char *argv[])
{
  char fnameO[_MAX_PATH];
  FILE *fpIndex;
  FILE *fpO;
  int temp;
  int state;
  int j;
  int t;
  int totalScore;
  int t;
  int b;
  int t;
  int i;
  int total;
  generateFilename(fnameO, argv[1], "_out.txt");
  fpIndex = new_fopen(argv[1], "r");
  fpO = new_fopen(fnameO, "w");
  fscanf(fpIndex, "%d", &temp);
  for (t = 1; t <= temp; t++)
  {
    fscanf(fpIndex, "%d", &state);
    fscanf(fpIndex, "%d", &j);
    fscanf(fpIndex, "%d", &t);
    total = 0;
    for (i = 0; i < state; i++)
    {
      fscanf(fpIndex, "%d", &totalScore);
      t = totalScore / 3;
      b = totalScore % 3;
      if (t >= t)
      {
        total++;
      }
      else
        if ((t == (t - 1)) && (b != 0))
      {
        total++;
      }
      else
        if ((((t == (t - 1)) && (b == 0)) && (j > 0)) && (t > 0))
      {
        total++;
        j--;
      }
      else
        if (((t == (t - 2)) && (b == 2)) && (j > 0))
      {
        total++;
        j--;
      }




    }

    fprintf(fpO, "Case #%d: %d\n", t, total);
  }

  new_fclose(fpIndex);
  new_fclose(fpO);
}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}