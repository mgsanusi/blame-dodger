#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  int T;
  int iT;
  scanf("%d", &T);
  static int a[105][256 + 5];
  static int atmp[256 + 5];
  for (iT = 0; iT < T; iT++)
  {
    int D;
    int I;
    int M;
    int N;
    scanf("%d %d %d %d", &D, &I, &M, &N);
    int i;
    int j;
    int k;
    for (i = 0; i < 256; i++)
      a[0][i] = 2000000000;

    a[0][256] = 0;
    for (i = 1; i <= N; i++)
    {
      for (j = 0; j <= 256; j++)
      {
        a[i][j] = 2000000000;
      }

      int num;
      int temp;
      scanf("%d", &num);
      for (j = 0; j <= 256; j++)
      {
        if (a[i - 1][j] != 2000000000)
        {
          temp = a[i - 1][j] + D;
          if (temp < a[i][j])
            a[i][j] = temp;

          for (k = 0; k < 256; k++)
          {
            if ((j == 256) || (abs(k - j) <= M))
            {
              temp = a[i - 1][j] + abs(k - num);
              if (temp < a[i][k])
                a[i][k] = temp;

            }

          }

          if ((j == 256) || (abs(num - j) <= M))
          {
            temp = a[i - 1][j];
            if (temp < a[i][num])
              a[i][num] = temp;

          }

        }

      }

      char flag = 1;
      while (flag)
      {
        flag = 0;
        atmp[256] = a[i][256];
        for (k = 0; k < 256; k++)
        {
          atmp[k] = a[i][k];
          for (j = 0; j <= 256; j++)
          {
            if ((j == 256) || (abs(k - j) <= M))
            {
              temp = a[i][j] + I;
              if (temp < atmp[k])
              {
                atmp[k] = temp;
                flag = 1;
              }

            }

          }

        }

        for (k = 0; k <= 256; k++)
          a[i][k] = atmp[k];

      }

    }

    int res = 2000000000;
    for (j = 0; j <= 256; j++)
    {
      if (a[N][j] < res)
        res = a[N][j];

    }

    printf("Case #%d: %d\n", iT + 1, res);
  }

  return 0;
}


