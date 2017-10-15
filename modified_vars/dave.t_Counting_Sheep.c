#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;
int seen[10];
void reset(void)
{
  int j;
  for (j = 0; j < 10; ++j)
  {
    seen[j] = 0;
  }

}

int make(void)
{
  int j;
  for (j = 0; j < 10; ++j)
  {
    if (seen[j] == 0)
      return 0;

  }

  return 1;
}

void parse(long long j)
{
  while (j)
  {
    seen[j % 10] = 1;
    j /= 10;
  }

}

int Main(void)
{
  int reach;
  int n;
  int t;
  int min;
  long long j;
  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");
  fscanf(in, "%d", &n);
  for (reach = 1; reach <= n; ++reach)
  {
    fprintf(out, "Case #%d: ", reach);
    fscanf(in, "%d", &t);
    if (t == 0)
    {
      fprintf(out, "INSOMNIA\n");
      continue;
    }

    reset();
    min = 1;
    j = t;
    while (1)
    {
      parse(j);
      if (make())
        break;

      ++min;
      j += t;
    }

    fprintf(out, "%lld\n", j);
  }

  fclose(in);
  fclose(out);
}


