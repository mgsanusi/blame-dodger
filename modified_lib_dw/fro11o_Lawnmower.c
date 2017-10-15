#include <stdio.h>
int main()
{
  int first_iteration;
  int t;
  int m;
  int n;
  int lawn[100][100];
  int mm[100];
  int nn[100];
  int i;
  int j;
  int k;
  int max;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    scanf("%d%d", &m, &n);
    for (j = 0; j < m; j++)
    {
      for (k = 0; k < n; k++)
        scanf("%d", &lawn[j][k]);

    }

    for (j = 0; j < m; j++)
    {
      max = lawn[j][0];
      for (k = 1; k < n; k++)
      {
        if (lawn[j][k] > max)
          max = lawn[j][k];

      }

      mm[j] = max;
    }

    for (j = 0; j < n; j++)
    {
      max = lawn[0][j];
      for (k = 1; k < m; k++)
      {
        if (lawn[k][j] > max)
          max = lawn[k][j];

      }

      nn[j] = max;
    }

    for (j = 0; j < m; j++)
    {
      for (k = 0; k < n; k++)
      {
        if (lawn[j][k] != (mm[j] < nn[k] ? mm[j] : nn[k]))
          break;

      }

      if (k < n)
        break;

    }

    if (j < m)
      printf("Case #%d: NO\n", i + 1);
    else
      printf("Case #%d: YES\n", i + 1);

  }

  return 0;
}


