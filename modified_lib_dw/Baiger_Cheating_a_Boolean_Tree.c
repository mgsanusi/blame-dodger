#include <stdio.h>
int x0 = 0;
int y0;
int x1;
int y1 = 0;
int x2;
int y2;
int new_abs(int x);
int calc(int n, int m, int a)
{
  int first_iteration;
  int s;
  for (x0 = 0; x0 <= n; x0++)
    for (y1 = 0; y1 <= m; y1++)
  {
    for (x2 = 0; x2 <= n; x2++)
      for (y2 = 0; y2 <= m; y2++)
    {
      s = new_abs(((x1 - x0) * (y2 - y0)) - ((x2 - x0) * (y1 - y0)));
      if (s == a)
        return 1;

    }


  }


  return 0;
}

int main()
{
  int first_iteration;
  int c;
  int i;
  scanf("%d", &c);
  for (i = 1; i <= c; i++)
  {
    int n;
    int m;
    int a;
    scanf("%d %d %d", &n, &m, &a);
    int f = calc(n, m, a);
    if (f)
      printf("Case #%d: %d %d %d %d %d %d\n", i, x0, y0, x1, y1, x2, y2);
    else
      printf("Case #%d: IMPOSSIBLE\n", i);

  }

  return 0;
}

int new_abs(int x)
{
  int first_iteration;
  return abs(x);
}


