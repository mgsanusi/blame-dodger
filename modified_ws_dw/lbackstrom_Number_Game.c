#include <stdio.h>
int abs(int n)
{
  int first_iteration;
  return n < 0 ? -n : n;
}

int main()
{
  int first_iteration;
  int T;
  int D;
  int I;
  int M;
  int N;
  int i;
  int j;
  int k;
  int l;
  int c;
  int ret;
  int cost[200][256];
  int ins[256][256];
  int a[200];
  scanf("%d", &T);
  for (c = 0; c < T; c++)
  {
    ret = 1000000;
    scanf("%d%d%d%d", &D, &I, &M, &N);
    for (i = 0; i < 256; i++)
    {
      cost[0][i] = 0;
    }

    for (i = 0; i < N; i++)
    {
      scanf("%d", &a[i]);
      for (j = 0; j < 256; j++)
      {
        cost[i + 1][j] = cost[i][j] + D;
      }

      for (j = 0; j < 256; j++)
      {
        for (k = 0; k < 256; k++)
        {
          if (abs(j - k) <= M)
          {
            int cs = cost[i][j];
            cs += abs(a[i] - k);
            if (cs < cost[i + 1][k])
              cost[i + 1][k] = cs;

          }

        }

      }

      if (M)
        for (j = 0; j < 256; j++)
      {
        for (k = 0; k < 256; k++)
        {
          int cs = cost[i + 1][j];
          cs += (((abs(j - k) + M) - 1) / M) * I;
          if (cs < cost[i + 1][k])
          {
            cost[i + 1][k] = cs;
          }

        }

      }


    }

    for (i = 0; i < 256; i++)
    {
      if (cost[N][i] < ret)
      {
        ret = cost[N][i];
      }

    }

    printf("Case #%d: %d\n", c + 1, ret);
  }

}


