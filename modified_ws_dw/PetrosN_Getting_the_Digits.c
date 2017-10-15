#include <stdio.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  FILE *fin;
  FILE *fout;
  fin = fopen("A-small-attempt2.in", "r");
  fout = fopen("output.txt", "w");
  int T;
  int i;
  int j;
  int q;
  int S[26];
  int N;
  int max = 0;
  int sum;
  int r1;
  int r2;
  int x;
  int k;
  char c;
  char c1;
  char c2;
  fscanf(fin, "%d", &T);
  for (q = 1; q <= T; q++)
  {
    sum = 0;
    fscanf(fin, "%d", &N);
    for (i = 0; i < N; i++)
    {
      fscanf(fin, "%d", &S[i]);
    }

    fprintf(fout, "Case #%d: ", q);
    for (i = 0; i < N; i++)
    {
      sum += S[i];
    }

    x = 0;
    for (i = 0; i < N; i++)
    {
      if (S[i])
        x++;

    }

    while (x > 2)
    {
      max = 0;
      for (j = 0; j < N; j++)
      {
        if (S[j] >= S[max])
          max = j;

      }

      c = 65 + max;
      S[max]--;
      fprintf(fout, "%c ", c);
      x = 0;
      for (k = 0; k < N; k++)
      {
        if (S[k] > 0)
          x++;

      }

    }

    for (i = 0; i < N; i++)
    {
      if (S[i])
      {
        r1 = i;
        break;
      }

    }

    for (i = r1 + 1; i < N; i++)
    {
      if (S[i])
      {
        r2 = i;
        break;
      }

    }

    c1 = r1 + 65;
    c2 = r2 + 65;
    for (i = 0; i < S[r2]; i++)
      fprintf(fout, "%c%c ", c1, c2);

    fprintf(fout, "\n");
  }

  fclose(fin);
  fclose(fout);
  return 0;
}


