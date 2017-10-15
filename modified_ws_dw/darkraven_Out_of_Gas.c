#include <stdio.h>
int check(int *x, int *y, int *r, int n)
{
  int first_iteration;
  int i;
  for (i = 0; i < n; i++)
  {
    unsigned long long dist = ((unsigned long long) (x[n] - x[i])) * ((unsigned long long) (x[n] - x[i]));
    dist += ((unsigned long long) (y[n] - y[i])) * ((unsigned long long) (y[n] - y[i]));
    if (dist < (((unsigned long long) (r[n] + r[i])) * ((unsigned long long) (r[n] + r[i]))))
      return 0;

  }

  return 1;
}

int x[11];
int y[11];
int r[11];
int main()
{
  int first_iteration;
  int t;
  int p;
  scanf("%d", &t);
  for (p = 1; p <= t; p++)
  {
    int n;
    int w;
    int l;
    scanf("%d%d%d", &n, &w, &l);
    int i;
    for (i = 0; i < n; i++)
      scanf("%d", r + i);

    for (i = 0; i < n; i++)
    {
      for (;;)
      {
        x[i] = rand() % (w + 1);
        y[i] = rand() % (l + 1);
        if (check(x, y, r, i))
          break;

      }

    }

    printf("Case #%d: ", p);
    for (i = 0; i < n; i++)
      printf("%d %d ", x[i], y[i]);

    printf("\n");
  }

  return 0;
}


