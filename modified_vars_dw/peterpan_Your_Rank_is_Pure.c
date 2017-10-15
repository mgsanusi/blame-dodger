#include <stdio.h>
int Main(int argc, char *argv[])
{
  int first_iteration;
  FILE *Fin;
  FILE *Fout;
  int tcase;
  int mark;
  int ansStr;
  int itest;
  int a;
  int d;
  int num[51];
  int v[51];
  int h;
  int counter;
  int swaps;
  if (argc > 1)
    Fin = fopen(argv[1], "r");
  else
    Fin = fopen("chicks.in", "r");

  if (!Fin)
    return 1;

  if (argc > 2)
    Fout = fopen(argv[2], "w");
  else
    Fout = fopen("chicks.out", "w");

  if (!Fout)
  {
    fclose(Fin);
    return 1;
  }

  fscanf(Fin, "%d", &mark);
  for (tcase = 1; tcase <= mark; tcase++)
  {
    fscanf(Fin, "%d", &itest);
    fscanf(Fin, "%d", &ansStr);
    fscanf(Fin, "%d", &a);
    fscanf(Fin, "%d", &d);
    for (h = 0; h < itest; h++)
      fscanf(Fin, "%d", num + h);

    for (h = 0; h < itest; h++)
      fscanf(Fin, "%d", v + h);

    counter = 0;
    swaps = 0;
    if (ansStr)
    {
      for (h = itest - 1; h >= 0; h--)
      {
        if ((num[h] + (v[h] * d)) >= a)
        {
          swaps += counter;
          if ((--ansStr) == 0)
            break;

        }
        else
          counter++;

      }

    }

    if (ansStr == 0)
      fprintf(Fout, "Case #%d: %d\r\n", tcase, swaps);
    else
      fprintf(Fout, "Case #%d: IMPOSSIBLE\r\n", tcase);

  }

  fclose(Fin);
  fclose(Fout);
  return 0;
}


