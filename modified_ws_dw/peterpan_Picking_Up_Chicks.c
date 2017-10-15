#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
  int first_iteration;
  FILE *fin;
  FILE *fout;
  int i;
  int j;
  int tcase;
  int T;
  int N;
  int M;
  int counter;
  int pos;
  char dirs[200][102];
  if (argc > 1)
    fin = fopen(argv[1], "r");
  else
    fin = fopen("fixit.in", "r");

  if (!fin)
    return 1;

  if (argc > 2)
    fout = fopen(argv[2], "w");
  else
    fout = fopen("fixit.out", "w");

  if (!fout)
  {
    fclose(fin);
    return 1;
  }

  fscanf(fin, "%d", &T);
  for (tcase = 1; tcase <= T; tcase++)
  {
    fscanf(fin, "%d", &N);
    fscanf(fin, "%d", &M);
    for (i = 0; i < N; i++)
      fscanf(fin, "%s", dirs[i]);

    for (i = 0; i < M; i++)
      fscanf(fin, "%s", dirs[i + N]);

    counter = 0;
    for (i = N; i < (N + M); i++)
    {
      pos = 0;
      j = 0;
      while (dirs[i][pos])
      {
        pos++;
        while (dirs[i][pos] && (dirs[i][pos] != '/'))
          pos++;

        while (j < i)
        {
          if ((strncmp(dirs[i], dirs[j], pos) == 0) && ((dirs[j][pos] == '/') || (dirs[j][pos] == 0)))
            break;

          j++;
        }

        if (j == i)
        {
          while (dirs[i][pos])
          {
            if (dirs[i][pos++] == '/')
              counter++;

          }

          counter++;
          break;
        }

      }

    }

    fprintf(fout, "Case #%d: %d\n", tcase, counter);
  }

  fclose(fin);
  fclose(fout);
  return 0;
}


