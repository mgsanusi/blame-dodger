#include <stdio.h>
#include <stdlib.h>
FILE *flipper;
FILE *Fout;
int now;
int x;
int l[701];
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

void clear()
{
  int first_iteration;
  fscanf(flipper, "%d %d", &now, &x);
  int pD;
  int least;
  int ans = 0;
  int xpGetargs;
  for (pD = 0; pD < 700; pD++)
    l[pD] = 0;

  for (pD = 0; pD < now; pD++)
  {
    fscanf(flipper, "%d", &xpGetargs);
    l[xpGetargs]++;
  }

  for (pD = 700; pD >= 1; pD--)
  {
    while (l[pD] > 0)
    {
      ans++;
      l[pD]--;
      for (least = x - pD; least >= 1; least--)
      {
        if (l[least] > 0)
        {
          l[least]--;
          break;
        }

      }

    }

  }

  fprintf(Fout, "%d\n", ans);
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  char kk;
  int total;
  int pD;
  flipper = new_fopen(argv[1], "r");
  Fout = new_fopen("out", "w");
  if ((flipper == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(flipper, "%d", &total);
    fscanf(flipper, "%c", &kk);
    for (pD = 0; pD < total; pD++)
    {
      fprintf(Fout, "Case #%d: ", pD + 1);
      clear();
    }

    new_fclose(flipper);
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