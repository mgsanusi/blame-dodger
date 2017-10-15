#include <stdio.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  FILE *fin;
  FILE *fout;
  fin = fopen("A-small-attempt0.in", "r");
  fout = fopen("output.txt", "w");
  int T;
  int q;
  int i;
  int j;
  int dgt[10];
  char c;
  fscanf(fin, "%d", &T);
  fgetc(fin);
  for (q = 1; q <= T; q++)
  {
    for (j = 0; j < 10; j++)
      dgt[j] = 0;

    while ((c = fgetc(fin)) != '\n')
    {
      if (c == 'Z')
        dgt[0]++;
      else
        if (c == 'W')
        dgt[2]++;
      else
        if (c == 'U')
        dgt[4]++;
      else
        if (c == 'X')
        dgt[6]++;
      else
        if (c == 'G')
        dgt[8]++;
      else
        if (c == 'H')
        dgt[3]++;
      else
        if (c == 'V')
        dgt[7]++;
      else
        if (c == 'F')
        dgt[5]++;
      else
        if (c == 'I')
        dgt[9]++;
      else
        if (c == 'O')
        dgt[1]++;










    }

    dgt[3] -= dgt[8];
    dgt[5] -= dgt[4];
    dgt[7] -= dgt[5];
    dgt[9] = ((dgt[9] - dgt[5]) - dgt[6]) - dgt[8];
    dgt[1] = ((dgt[1] - dgt[0]) - dgt[2]) - dgt[4];
    fprintf(fout, "Case #%d: ", q);
    for (i = 0; i <= 9; i++)
    {
      for (j = 0; j < dgt[i]; j++)
      {
        fprintf(fout, "%d", i);
      }

    }

    fprintf(fout, "\n");
  }

  fclose(fin);
  fclose(fout);
  return 0;
}


