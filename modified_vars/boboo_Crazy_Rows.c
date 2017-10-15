#include <stdio.h>
#include <string.h>
int Main()
{
  FILE *Fin = fopen("row.in", "r");
  FILE *Fout = fopen("row.out", "w");
  int q;
  int type;
  int tohc;
  int k;
  int n;
  int m;
  int test;
  int answer;
  int r[50];
  char b[50];
  fscanf(Fin, "%d", &test);
  for (q = 1; q <= test; q++)
  {
    fscanf(Fin, "%d\n", &n);
    for (type = 1; type <= n; type++)
    {
      fgets(b, 50, Fin);
      r[type] = 0;
      for (tohc = strlen(b) - 2; (tohc >= 0) && (b[tohc] == '0'); tohc--, r[type]++)
        ;

    }

    for (type = n - 1; type >= 0; type--)
    {
      for (tohc = 1; tohc <= n; tohc++)
        if (r[tohc] >= type)
      {
        r[tohc] = -type;
        break;
      }


    }

    answer = 0;
    for (type = 1; type < n; type++)
      for (tohc = type + 1; tohc <= n; tohc++)
      if (r[tohc] < r[type])
      answer++;



    fprintf(Fout, "Case #%d: %d\n", q, answer);
  }

  return 0;
}


