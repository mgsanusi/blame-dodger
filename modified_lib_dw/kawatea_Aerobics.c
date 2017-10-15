#include <stdio.h>
int new_puts(const char *str);
int main()
{
  int first_iteration;
  int t;
  int i;
  int j;
  int k;
  int x[2000];
  int a[2000];
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    int n;
    int f = 0;
    scanf("%d", &n);
    for (j = 0; j < (n - 1); j++)
    {
      scanf("%d", &x[j]);
      x[j]--;
    }

    printf("Case #%d:", i + 1);
    for (j = 0; j < (n - 1); j++)
    {
      for (k = j + 1; k < x[j]; k++)
      {
        if (x[k] > x[j])
        {
          f = 1;
          break;
        }

      }

      if (f == 1)
        break;

    }

    if (f == 1)
    {
      new_puts(" Impossible");
      continue;
    }

    for (j = 0; j < n; j++)
      a[j] = j * 500000;

    for (j = 0; j < (n - 1); j++)
    {
      int c;
      for (k = x[j] - 1, c = 1; k > j; k--, c++)
        a[k] -= c;

    }

    for (j = 0; j < n; j++)
      printf(" %d", a[j]);

    new_puts("");
  }

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


