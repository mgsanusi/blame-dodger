#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
void clear()
{
  char a;
  char l;
  int s = 0;
  fscanf(Fin, "%c", &a);
  fscanf(Fin, "%c", &l);
  while (l != '\n')
  {
    if (l != a)
    {
      a = l;
      s++;
    }

    fscanf(Fin, "%c", &l);
  }

  if (a == '-')
    s++;

  fprintf(Fout, "%d\n", s);
}

int Main(int argc, char *argv[])
{
  char type;
  int total;
  int n;
  Fin = fopen(argv[1], "r");
  Fout = fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &total);
    fscanf(Fin, "%c", &type);
    for (n = 0; n < total; n++)
    {
      fprintf(Fout, "Case #%d: ", n + 1);
      clear();
    }

    fclose(Fin);
    fclose(Fout);
  }

  return 0;
}


