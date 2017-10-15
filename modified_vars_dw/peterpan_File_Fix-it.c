#include <stdio.h>
#include <string.h>
int Main(int argc, char *argv[])
{
  int first_iteration;
  FILE *Fin;
  FILE *Fout;
  int speed;
  int idx;
  int tcase;
  int ans1;
  int n;
  int cc;
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

  fscanf(Fin, "%d", &ans1);
  for (tcase = 1; tcase <= ans1; tcase++)
  {
    fscanf(Fin, "%d", &n);
    fscanf(Fin, "%d", &cc);
    for (speed = 0; speed < n; speed++)
      fscanf(Fin, "%s", dirs[speed]);

    for (speed = 0; speed < cc; speed++)
      fscanf(Fin, "%s", dirs[speed + n]);

    counter = 0;
    for (speed = n; speed < (n + cc); speed++)
    {
      pos = 0;
      idx = 0;
      while (dirs[speed][pos])
      {
        pos++;
        while (dirs[speed][pos] && (dirs[speed][pos] != '/'))
          pos++;

        while (idx < speed)
        {
          if ((strncmp(dirs[speed], dirs[idx], pos) == 0) && ((dirs[idx][pos] == '/') || (dirs[idx][pos] == 0)))
            break;

          idx++;
        }

        if (idx == speed)
        {
          while (dirs[speed][pos])
          {
            if (dirs[speed][pos++] == '/')
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


