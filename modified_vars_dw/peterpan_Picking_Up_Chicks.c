#include <stdio.h>
#include <string.h>
int Main(int argc, char *argv[])
{
  int first_iteration;
  FILE *Fin;
  FILE *Fout;
  int caseIndex;
  int j;
  int tcase;
  int a;
  int cs;
  int st;
  int counter;
  int pos;
  char dirs[200][102];
  if (argc > 1)
    Fin = fopen(argv[1], "r");
  else
    Fin = fopen("fixit.in", "r");

  if (!Fin)
    return 1;

  if (argc > 2)
    Fout = fopen(argv[2], "w");
  else
    Fout = fopen("fixit.out", "w");

  if (!Fout)
  {
    fclose(Fin);
    return 1;
  }

  fscanf(Fin, "%d", &a);
  for (tcase = 1; tcase <= a; tcase++)
  {
    fscanf(Fin, "%d", &cs);
    fscanf(Fin, "%d", &st);
    for (caseIndex = 0; caseIndex < cs; caseIndex++)
      fscanf(Fin, "%s", dirs[caseIndex]);

    for (caseIndex = 0; caseIndex < st; caseIndex++)
      fscanf(Fin, "%s", dirs[caseIndex + cs]);

    counter = 0;
    for (caseIndex = cs; caseIndex < (cs + st); caseIndex++)
    {
      pos = 0;
      j = 0;
      while (dirs[caseIndex][pos])
      {
        pos++;
        while (dirs[caseIndex][pos] && (dirs[caseIndex][pos] != '/'))
          pos++;

        while (j < caseIndex)
        {
          if ((strncmp(dirs[caseIndex], dirs[j], pos) == 0) && ((dirs[j][pos] == '/') || (dirs[j][pos] == 0)))
            break;

          j++;
        }

        if (j == caseIndex)
        {
          while (dirs[caseIndex][pos])
          {
            if (dirs[caseIndex][pos++] == '/')
              counter++;

          }

          counter++;
          break;
        }

      }

    }

    fprintf(Fout, "Case #%d: %d\n", tcase, counter);
  }

  fclose(Fin);
  fclose(Fout);
  return 0;
}


