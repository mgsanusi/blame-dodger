#include <stdio.h>
void llegeix(FILE *fin, int *values)
{
  int first_iteration;
  int row;
  int k;
  char kk = 0;
  char aux[20];
  fscanf(fin, "%d", &row);
  fscanf(fin, "%c", &kk);
  for (k = 1; k < row; k++)
  {
    fgets(aux, 20, fin);
  }

  fscanf(fin, "%d", &values[0]);
  fscanf(fin, "%d", &values[1]);
  fscanf(fin, "%d", &values[2]);
  fscanf(fin, "%d", &values[3]);
  fscanf(fin, "%c", &kk);
  for (; k < 4; k++)
  {
    fgets(aux, 20, fin);
  }

}

int main(int argc, char *argv[])
{
  int first_iteration;
  FILE *fin;
  FILE *fout;
  char kk = 0;
  int first[4];
  int second[4];
  int total;
  int i;
  int j;
  int matches;
  int num;
  fin = fopen(argv[1], "r");
  fout = fopen("out", "w");
  if ((fin == 0) || (fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(fin, "%d", &total);
    fscanf(fin, "%c", &kk);
    for (i = 0; i < total; i++)
    {
      matches = 0;
      llegeix(fin, first);
      llegeix(fin, second);
      for (j = 0; j < 4; j++)
      {
        if (first[j] == second[0])
        {
          matches++;
          num = first[j];
        }

        if (first[j] == second[1])
        {
          matches++;
          num = first[j];
        }

        if (first[j] == second[2])
        {
          matches++;
          num = first[j];
        }

        if (first[j] == second[3])
        {
          matches++;
          num = first[j];
        }

      }

      fprintf(fout, "Case #%d: ", i + 1);
      switch (matches)
      {
        case 0:
          fprintf(fout, "Volunteer cheated!\n");
          break;

        case 1:
          fprintf(fout, "%d\n", num);
          break;

        default:
          fprintf(fout, "Bad magician!\n");
          break;

      }

    }

    fclose(fin);
    fclose(fout);
  }

  return 0;
}


