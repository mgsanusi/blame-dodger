#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *Fin;
FILE *Fout;
int d[30];
char a[102];
int flag;
int sx;
int t;
int c(int sq)
{
  int list;
  int val = 0;
  for (list = sq; list < sx; list++, val++)
  {
    if (a[list] != a[val])
    {
      return 0;
    }

  }

  return 1;
}

int on(int m)
{
  int aux;
  aux = t - sx;
  return (aux / m) + 1;
}

void clear()
{
  int list;
  char kk;
  int m;
  for (list = 0; list < 30; list++)
    d[list] = 0;

  fscanf(Fin, "%d %d %d", &flag, &sx, &t);
  fscanf(Fin, "%c", &kk);
  for (list = 0; list < flag; list++)
  {
    fscanf(Fin, "%c", &kk);
    d[kk - 'A']++;
  }

  fscanf(Fin, "%c", &kk);
  for (list = 0; list < sx; list++)
  {
    fscanf(Fin, "%c", &a[list]);
  }

  a[list] = '\0';
  fscanf(Fin, "%c", &kk);
  double prob = 1;
  for (list = 0; list < sx; list++)
  {
    if (d[a[list] - 'A'] == 0)
    {
      fprintf(Fout, "0.0\n");
      return;
    }

    prob = (prob * (d[a[list] - 'A'] * 1.0)) / (flag * 1.0);
  }

  m = sx;
  for (list = 1; list < sx; list++)
  {
    if (c(list))
    {
      m = list;
      break;
    }

  }

  fprintf(Fout, "%lf\n", ((double) on(m)) - (prob * ((t - sx) + 1)));
}

int Main(int argc, char *argv[])
{
  char kk;
  int total;
  int list;
  Fin = fopen(argv[1], "r");
  Fout = fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &total);
    fscanf(Fin, "%c", &kk);
    for (list = 0; list < total; list++)
    {
      fprintf(Fout, "Case #%d: ", list + 1);
      printf("Case #%d: ", list + 1);
      clear();
    }

    fclose(Fin);
    fclose(Fout);
  }

  return 0;
}


