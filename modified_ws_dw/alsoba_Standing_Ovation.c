#include <stdio.h>
#include <stdlib.h>
FILE *fin;
FILE *fout;
int Smax;
void solve()
{
  int first_iteration;
  char c;
  int i;
  int total = 0;
  int sol = 0;
  fscanf(fin, "%d", &Smax);
  fscanf(fin, "%c", &c);
  for (i = 0; i < (Smax + 1); i++)
  {
    fscanf(fin, "%c", &c);
    if (total < i)
    {
      sol = (sol + i) - total;
      total = i;
    }

    total = (total + c) - '0';
  }

  fprintf(fout, "%d\n", sol);
}

int main(int argc, char *argv[])
{
  int first_iteration;
  char kk;
  int total;
  int i;
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
      fprintf(fout, "Case #%d: ", i + 1);
      solve();
    }

    fclose(fin);
    fclose(fout);
  }

  return 0;
}


