#include <stdio.h>
int new_abs(int x);

int new_abs(int b)
{
  int first_iteration;
  return b < 0 ? -b : b;
}

int Main()
{
  int first_iteration;
  int v;
  int atx;
  int startingPoint;
  int m;
  int n;
  int i;
  int position;
  int k;
  int start;
  int d;
  int ret;
  int cost[200][256];
  int ins[256][256];
  int a[200];
  scanf("%d", &v);
  for (d = 0; d < v; d++)
  {
    ret = 1000000;
    scanf("%d%d%d%d", &atx, &startingPoint, &m, &n);
    for (i = 0; i < 256; i++)
    {
      cost[0][i] = 0;
    }

    for (i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      for (position = 0; position < 256; position++)
      {
        cost[i + 1][position] = cost[i][position] + atx;
      }

      for (position = 0; position < 256; position++)
      {
        for (k = 0; k < 256; k++)
        {
          if (new_abs(position - k) <= m)
          {
            int lx = cost[i][position];
            lx += new_abs(a[i] - k);
            if (lx < cost[i + 1][k])
              cost[i + 1][k] = lx;

          }

        }

      }

      if (m)
        for (position = 0; position < 256; position++)
      {
        for (k = 0; k < 256; k++)
        {
          int lx = cost[i + 1][position];
          lx += (((new_abs(position - k) + m) - 1) / m) * startingPoint;
          if (lx < cost[i + 1][k])
          {
            cost[i + 1][k] = lx;
          }

        }

      }


    }

    for (i = 0; i < 256; i++)
    {
      if (cost[n][i] < ret)
      {
        ret = cost[n][i];
      }

    }

    printf("Case #%d: %d\n", d + 1, ret);
  }

}



int new_abs(int x) {
  return abs(x);
}