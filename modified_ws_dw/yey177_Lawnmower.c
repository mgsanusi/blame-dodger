#include <stdio.h>
int d[102][102];
int main()
{
  int first_iteration;
  int t;
  int n;
  int m;
  int i;
  int j;
  int k;
  int x;
  int max;
  int min;
  int f;
  scanf("%d", &t);
  for (x = 1; x <= t; x++)
  {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
      scanf("%d", &d[i][j]);


    f = 1;
    for (k = 1; k <= 100; k++)
    {
      for (i = 0; i < n; i++)
      {
        min = 101;
        max = 0;
        for (j = 0; j < m; j++)
        {
          if (d[i][j])
          {
            min = min < d[i][j] ? min : d[i][j];
            max = max > d[i][j] ? max : d[i][j];
          }

        }

        if ((min == k) && (max == k))
        {
          for (j = 0; j < m; j++)
            d[i][j] = 0;

        }

      }

      for (j = 0; j < m; j++)
      {
        min = 101;
        max = 0;
        for (i = 0; i < n; i++)
        {
          if (d[i][j])
          {
            min = min < d[i][j] ? min : d[i][j];
            max = max > d[i][j] ? max : d[i][j];
          }

        }

        if ((min == k) && (max == k))
        {
          for (i = 0; i < n; i++)
            d[i][j] = 0;

        }

      }

      for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
      {
        if (d[i][j] == k)
        {
          f = 0;
          goto END;
        }

      }


    }

    END:
    printf("Case #%d: %s\n", x, f ? "YES" : "NO");

  }

  return 0;
}


