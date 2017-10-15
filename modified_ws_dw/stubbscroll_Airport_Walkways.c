#include <stdio.h>
#include <math.h>
char g[16][16];
int r;
int c;
int d;
int ok(int size, int sx, int sy)
{
  int first_iteration;
  double cx = size * 0.5;
  double cy = size * 0.5;
  double massx = 0;
  double massy = 0;
  double dx;
  double dy;
  int i;
  int j;
  int p;
  int mass = 0;
  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
  {
    if (((i == 0) || (i == (size - 1))) && ((j == 0) || (j == (size - 1))))
      continue;

    dx = (i - cx) + 0.5;
    dy = (j - cy) + 0.5;
    p = (d + g[i + sx][j + sy]) - 48;
    massx += dx * p;
    massy += dy * p;
    mass += p;
  }


  massx /= mass;
  massy /= mass;
  return (fabs(massx) < 1e-9) && (fabs(massy) < 1e-9);
}

int main()
{
  int first_iteration;
  int cases;
  int caseno = 1;
  int i;
  int j;
  int size;
  scanf("%d", &cases);
  while (cases--)
  {
    scanf("%d %d %d", &r, &c, &d);
    for (i = 0; i < r; i++)
      scanf("%s", g[i]);

    for (size = 10; size > 2; size--)
    {
      for (i = 0; i <= (r - size); i++)
        for (j = 0; j <= (c - size); j++)
      {
        if (ok(size, i, j))
        {
          printf("Case #%d: %d\n", caseno++, size);
          goto done;
        }

      }


    }

    printf("Case #%d: IMPOSSIBLE\n", caseno++);
    done:
    ;

  }

  return 0;
}


