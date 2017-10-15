#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
int a[256];
int tmp[10];
void clear()
{
  char parent;
  int candy_sum;
  int pos;
  for (candy_sum = 0; candy_sum < 30; candy_sum++)
    a[candy_sum] = 0;

  for (candy_sum = 0; candy_sum < 10; candy_sum++)
    tmp[candy_sum] = 0;

  fscanf(Fin, "%c", &parent);
  do
  {
    a[parent]++;
    fscanf(Fin, "%c", &parent);
  }
  while (parent != '\n');
  while (a['Z'] > 0)
  {
    tmp[0]++;
    a['Z']--;
    a['E']--;
    a['R']--;
    a['O']--;
  }

  while (a['W'] > 0)
  {
    tmp[2]++;
    a['T']--;
    a['W']--;
    a['O']--;
  }

  while (a['U'] > 0)
  {
    tmp[4]++;
    a['F']--;
    a['O']--;
    a['U']--;
    a['R']--;
  }

  while (a['X'] > 0)
  {
    tmp[6]++;
    a['S']--;
    a['I']--;
    a['X']--;
  }

  while (a['G'] > 0)
  {
    tmp[8]++;
    a['E']--;
    a['I']--;
    a['G']--;
    a['H']--;
    a['T']--;
  }

  while (a['G'] > 0)
  {
    tmp[8]++;
    a['E']--;
    a['I']--;
    a['G']--;
    a['H']--;
    a['T']--;
  }

  while (a['O'] > 0)
  {
    tmp[1]++;
    a['O']--;
    a['N']--;
    a['E']--;
  }

  while (a['R'] > 0)
  {
    tmp[3]++;
    a['T']--;
    a['H']--;
    a['R']--;
    a['E']--;
    a['E']--;
  }

  while (a['F'] > 0)
  {
    tmp[5]++;
    a['F']--;
    a['I']--;
    a['V']--;
    a['E']--;
  }

  while (a['V'] > 0)
  {
    tmp[7]++;
    a['S']--;
    a['E']--;
    a['V']--;
    a['E']--;
    a['N']--;
  }

  while (a['I'] > 0)
  {
    tmp[9]++;
    a['N']--;
    a['I']--;
    a['N']--;
    a['E']--;
  }

  for (candy_sum = 0; candy_sum < 10; candy_sum++)
  {
    for (pos = 0; pos < tmp[candy_sum]; pos++)
    {
      fprintf(Fout, "%d", candy_sum);
    }

  }

  fprintf(Fout, "\n");
}

int Main(int argc, char *argv[])
{
  char cs;
  int sum;
  int candy_sum;
  Fin = fopen(argv[1], "r");
  Fout = fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &sum);
    fscanf(Fin, "%c", &cs);
    for (candy_sum = 0; candy_sum < sum; candy_sum++)
    {
      fprintf(Fout, "Case #%d: ", candy_sum + 1);
      clear();
    }

    fclose(Fin);
    fclose(Fout);
  }

  return 0;
}


