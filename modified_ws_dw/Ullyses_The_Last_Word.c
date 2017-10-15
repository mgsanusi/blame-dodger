#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int main()
{
  int first_iteration;
  FILE *fp;
  FILE *fo;
  fo = fopen("outputa.txt", "w");
  fp = fopen("inputa.in", "r");
  int T;
  int i;
  int j;
  int first;
  int last;
  int kl;
  char an[3002];
  char c;
  fscanf(fp, "%d", &T);
  if (fgetc(fp) == '\n')
  {
    printf("hi");
  }

  for (kl = 1; kl <= T; kl++)
  {
    fprintf(fo, "Case #");
    fprintf(fo, "%d", kl);
    fprintf(fo, ":");
    fprintf(fo, " ");
    first = 0;
    last = 0;
    c = fgetc(fp);
    while (c != '\n')
    {
      if (first == 0)
      {
        an[1001] = c;
        first = 1001;
        last = 1001;
      }
      else
      {
        if (c >= an[first])
        {
          first = first - 1;
          an[first] = c;
        }
        else
        {
          last = last + 1;
          an[last] = c;
        }

      }

      c = fgetc(fp);
    }

    for (i = first; i <= last; i++)
    {
      fprintf(fo, "%c", an[i]);
    }

    fprintf(fo, "\n");
  }

  return 1;
}


