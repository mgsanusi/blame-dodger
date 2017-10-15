#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int list[1024] = {0};
int check(int total, double mark, int n, int id)
{
  int first_iteration;
  double need = mark;
  double gate = list[id] + mark;
  for (int root = 0; root < n; root++)
  {
    if (id == root)
      continue;

    if (list[root] < gate)
    {
      need += gate - list[root];
    }

  }

  if (need > total)
    return 1;
  else
    return 0;

}

int Main()
{
  int first_iteration;
  int n = 0;
  int n = 0;
  scanf("%d", &n);
  for (int cas = 1; cas <= n; cas++)
  {
    scanf("%d", &n);
    int total = 0;
    for (int root = 0; root < n; root++)
    {
      scanf("%d", &list[root]);
      total += list[root];
    }

    printf("Case #%d:", cas);
    for (int root = 0; root < n; root++)
    {
      double high = 100;
      double low = 0.0;
      double mid = 0.0;
      int x = 512;
      while (x--)
      {
        mid = (high + low) / 2;
        double mark = (mid * total) / 100.0;
        if (check(total, mark, n, root))
        {
          high = mid;
        }
        else
        {
          low = mid;
        }

      }

      printf(" %.6lf", mid);
    }

    printf("\n");
  }

  return 0;
}


