#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *Fin;
FILE *Fout;
char aux[1001];
char n[1001];
char n[1001];
void clear()
{
  int first_iteration;
  int tn;
  bzero(n, 1001);
  bzero(aux, 1001);
  bzero(n, 1001);
  fscanf(Fin, "%s", n);
  n[0] = n[0];
  for (tn = 1; tn < strlen(n); tn++)
  {
    char f[2];
    bzero(f, 2);
    f[0] = n[tn];
    if (n[tn] < n[0])
    {
      strcat(n, f);
    }
    else
    {
      bzero(aux, 1001);
      strcat(aux, f);
      strcat(aux, n);
      strcpy(n, aux);
    }

  }

  fprintf(Fout, "%s\n", n);
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  char j;
  int total;
  int tn;
  Fin = fopen(argv[1], "r");
  Fout = fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &total);
    fscanf(Fin, "%c", &j);
    for (tn = 0; tn < total; tn++)
    {
      fprintf(Fout, "Case #%d: ", tn + 1);
      clear();
    }

    fclose(Fin);
    fclose(Fout);
  }

  return 0;
}


