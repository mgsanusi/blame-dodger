#include <stdio.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  FILE *fin;
  FILE *fout;
  fin = fopen("D-small-attempt0.in", "r");
  fout = fopen("output.txt", "w");
  int T;
  int K;
  int C;
  int S;
  int i;
  int j;
  fscanf(fin, "%d", &T);
  for (i = 1; i <= T; i++)
  {
    fscanf(fin, "%d", &K);
    fscanf(fin, "%d", &C);
    fscanf(fin, "%d", &S);
    fprintf(fout, "Case #%d: ", i);
    for (j = 1; j <= K; j++)
      fprintf(fout, "%d ", j);

    fprintf(fout, "\n");
  }

  return 0;
}


