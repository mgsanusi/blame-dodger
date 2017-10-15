#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Main()
{
  int t;
  int cases;
  scanf("%d", &t);
  static int front[2100];
  static int tot[2100][2100];
  static int t[2100][2100][15];
  for (cases = 0; cases < t; cases++)
  {
    int l;
    int first;
    scanf("%d", &l);
    first = 1 << l;
    int d;
    for (d = 0; d < first; d++)
    {
      scanf("%d", &front[d]);
      front[d] = l - front[d];
    }

    int temp = 1 << l;
    int prc = 0;
    int j;
    int k;
    do
    {
      prc++;
      temp /= 2;
      for (j = 0; j < temp; j++)
        scanf("%d", &tot[prc][j]);

    }
    while (temp > 1);
    for (j = 0; j < first; j++)
    {
      for (k = 0; k <= l; k++)
        t[0][j][k] = 1000000005;

      t[0][j][front[j]] = 0;
    }

    temp = 1 << l;
    int c;
    int c;
    int sum;
    for (d = 1; d <= prc; d++)
    {
      temp /= 2;
      for (j = 0; j < temp; j++)
      {
        for (k = 0; k <= l; k++)
        {
          t[d][j][k] = 1000000005;
          if (k < l)
          {
            c = k + 1;
            for (c = 0; c <= (k + 1); c++)
            {
              sum = (tot[d][j] + t[d - 1][2 * j][c]) + t[d - 1][(2 * j) + 1][c];
              if (sum < t[d][j][k])
                t[d][j][k] = sum;

            }

            c = k + 1;
            for (c = 0; c <= (k + 1); c++)
            {
              sum = (tot[d][j] + t[d - 1][2 * j][c]) + t[d - 1][(2 * j) + 1][c];
              if (sum < t[d][j][k])
                t[d][j][k] = sum;

            }

          }

          c = k;
          for (c = 0; c <= k; c++)
          {
            sum = t[d - 1][2 * j][c] + t[d - 1][(2 * j) + 1][c];
            if (sum < t[d][j][k])
              t[d][j][k] = sum;

          }

          c = k;
          for (c = 0; c <= k; c++)
          {
            sum = t[d - 1][2 * j][c] + t[d - 1][(2 * j) + 1][c];
            if (sum < t[d][j][k])
              t[d][j][k] = sum;

          }

        }

      }

    }

    printf("Case #%d: %d\n", cases + 1, t[prc][0][0]);
  }

  return 0;
}


