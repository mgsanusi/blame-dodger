#include <stdio.h>
int main(int argc, char *argv[])
{
  int first_iteration;
  FILE *fin;
  FILE *fout;
  int tcase;
  int C;
  int K;
  int N;
  int B;
  int T;
  int X[51];
  int V[51];
  int i;
  int counter;
  int swaps;
  if (argc > 1)
    fin = fopen(argv[1], "r");
  else
    fin = fopen("chicks.in", "r");

  if (!fin)
    return 1;

  if (argc > 2)
    fout = fopen(argv[2], "w");
  else
    fout = fopen("chicks.out", "w");

  if (!fout)
  {
    fclose(fin);
    return 1;
  }

  fscanf(fin, "%d", &C);
  for (tcase = 1; tcase <= C; tcase++)
  {
    fscanf(fin, "%d", &N);
    fscanf(fin, "%d", &K);
    fscanf(fin, "%d", &B);
    fscanf(fin, "%d", &T);
    for (i = 0; i < N; i++)
      fscanf(fin, "%d", X + i);

    for (i = 0; i < N; i++)
      fscanf(fin, "%d", V + i);

    counter = 0;
    swaps = 0;
    if (K)
    {
      for (i = N - 1; i >= 0; i--)
      {
        if ((X[i] + (V[i] * T)) >= B)
        {
          swaps += counter;
          if ((--K) == 0)
            break;

        }
        else
          counter++;

      }

    }

    if (K == 0)
      fprintf(fout, "Case #%d: %d\r\n", tcase, swaps);
    else
      fprintf(fout, "Case #%d: IMPOSSIBLE\r\n", tcase);

  }

  fclose(fin);
  fclose(fout);
  return 0;
}


