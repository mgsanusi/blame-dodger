#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ti;
int tn;
int tc;
int j;
int v;
int line;
int t;
int mem[50];
int b[50];
int can[2000001];
int from[2000001];
int lastmax;
int fir;
int new_putchar(int character);

int Main()
{
  scanf("%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
  {
    printf("Case #%d:\n", ti);
    scanf("%d", &line);
    for (tc = 0; tc < line; ++tc)
      scanf("%d", &mem[tc]);

    for (tc = 1; tc < (1 << line); ++tc)
    {
      for (j = (t = (b[0] = 0)); j < line; ++j)
      {
        if (tc & (1 << j))
          t += mem[j];
        else
          b[++b[0]] = mem[j];

      }

      memset(can, 0, sizeof(can));
      can[lastmax = 0] = 1;
      for (j = 1; j <= b[0]; ++j)
      {
        for (v = lastmax; v >= 0; --v)
          if (can[v])
        {
          can[v + b[j]] = 1;
          from[v + b[j]] = v;
          if ((v + b[j]) == t)
            break;

        }


        if (v >= 0)
          break;

        lastmax += b[j];
      }

      if (j <= b[0])
      {
        for (v = 0, fir = 1; v < line; ++v)
          if (tc & (1 << v))
        {
          if (!fir)
            new_putchar(' ');
          else
            fir = 0;

          printf("%d", mem[v]);
        }


        new_putchar('\n');
        for (fir = 1; t; t = from[t])
        {
          if (!fir)
            new_putchar(' ');
          else
            fir = 0;

          printf("%d", t - from[t]);
        }

        new_putchar('\n');
        break;
      }

    }

    if (tc == (1 << line))
      printf("Impossible\n");

  }

  return 0;
}



int new_putchar(int character) {
  return putchar(character);
}