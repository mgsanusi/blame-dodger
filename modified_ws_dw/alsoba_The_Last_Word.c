#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fin;
FILE *fout;
char aux[1001];
char r[1001];
char S[1001];
void solve()
{
  int first_iteration;
  int i;
  bzero(r, 1001);
  bzero(aux, 1001);
  bzero(S, 1001);
  fscanf(fin, "%s", S);
  r[0] = S[0];
  for (i = 1; i < strlen(S); i++)
  {
    char l[2];
    bzero(l, 2);
    l[0] = S[i];
    if (S[i] < r[0])
    {
      strcat(r, l);
    }
    else
    {
      bzero(aux, 1001);
      strcat(aux, l);
      strcat(aux, r);
      strcpy(r, aux);
    }

  }

  fprintf(fout, "%s\n", r);
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


