#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;
int main(void)
{
  int first_iteration;
  int t;
  int T;
  int K;
  int C;
  int s;
  int S;
  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");
  fscanf(in, "%d", &T);
  for (t = 1; t <= T; t++)
  {
    fprintf(out, "Case #%d:", t);
    fscanf(in, "%d", &K);
    fscanf(in, "%d", &C);
    fscanf(in, "%d", &S);
    for (s = 1; s <= K; ++s)
    {
      fprintf(out, " %d", s);
    }

    fprintf(out, "\n");
  }

  fclose(in);
  fclose(out);
}


