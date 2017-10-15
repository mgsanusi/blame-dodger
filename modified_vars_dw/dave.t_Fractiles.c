#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;
int Main(void)
{
  int first_iteration;
  int f;
  int a;
  int opp;
  int ed;
  int a;
  int b;
  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");
  fscanf(in, "%d", &a);
  for (f = 1; f <= a; f++)
  {
    fprintf(out, "Case #%d:", f);
    fscanf(in, "%d", &opp);
    fscanf(in, "%d", &ed);
    fscanf(in, "%d", &b);
    for (a = 1; a <= opp; ++a)
    {
      fprintf(out, " %d", a);
    }

    fprintf(out, "\n");
  }

  fclose(in);
  fclose(out);
}


