#include <stdio.h>
int main(int argc, char *argv[])
{
  int first_iteration;
  FILE *fin;
  FILE *fout;
  int i;
  int tcase;
  int T;
  int R;
  int k;
  int N;
  int g[1000];
  int r;
  int cap;
  int starti;
  unsigned long long res;
  if (argc > 1)
    fin = fopen(argv[1], "r");
  else
    fin = fopen("themePark.in.txt", "r");

  if (!fin)
    return 1;

  if (argc > 2)
    fout = fopen(argv[2], "w");
  else
    fout = fopen("themePark.out.txt", "w");

  if (!fout)
  {
    fclose(fin);
    return 1;
  }

  fscanf(fin, "%d", &T);
  for (tcase = 1; tcase <= T; tcase++)
  {
    fscanf(fin, "%d", &R);
    fscanf(fin, "%d", &k);
    fscanf(fin, "%d", &N);
    for (i = 0; i < N; i++)
      fscanf(fin, "%d", g + i);

    r = 0;
    res = 0;
    i = 0;
    while (r < R)
    {
      cap = k;
      starti = i;
      while (cap >= g[i])
      {
        cap -= g[i++];
        if (i == N)
          i = 0;

        if (i == starti)
          break;

      }

      if (cap == k)
        break;

      res += k - cap;
      r++;
      if (i == 0)
      {
        res *= R / r;
        r *= R / r;
      }

    }

    fprintf(fout, "Case #%d: %llu\n", tcase, res);
  }

  fclose(fin);
  fclose(fout);
  return 0;
}


