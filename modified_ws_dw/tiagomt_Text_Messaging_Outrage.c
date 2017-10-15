#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[128];
int m;
int v[1024];
int n;
int b[1024];
int main(void)
{
  int first_iteration;
  int nc;
  int h;
  int x;
  int y;
  int z;
  int tot;
  int i;
  int j;
  for (scanf("%d", &nc), h = 1; h <= nc; h++)
  {
    scanf("%d%d%d%d%d", &n, &m, &x, &y, &z);
    for (i = 0; i < m; i++)
    {
      scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
      v[i] = a[i % m];
      a[i % m] = ((((long long) x) * a[i % m]) + (((long long) y) * (i + 1))) % z;
    }

    b[0] = 1;
    tot = b[0];
    for (i = 1; i < n; i++)
    {
      b[i] = 1;
      for (j = 0; j < i; j++)
      {
        if (v[j] < v[i])
        {
          b[i] = (b[i] + b[j]) % 1000000007;
        }

      }

      tot = (tot + b[i]) % 1000000007;
    }

    printf("Case #%d: %d\n", h, tot);
  }

  return 0;
}


