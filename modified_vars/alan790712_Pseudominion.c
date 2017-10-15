#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Walk
{
  double b;
  double e;
  double w;
  double length;
} walk[1234];
int cmp(const void *x2, const void *b)
{
  struct Walk k = *((struct Walk *) x2);
  struct Walk p = *((struct Walk *) b);
  if (k.w > p.w)
    return 1;

  if (k.w < p.w)
    return -1;

  return 0;
}

int Main()
{
  int steps;
  int j;
  int t;
  int Case;
  double m;
  double arr;
  double r;
  int n;
  double fg2;
  double time;
  double temp;
  scanf(" %d", &Case);
  for (t = 1; t <= Case; ++t)
  {
    scanf(" %lf %lf %lf %lf %d", &m, &arr, &r, &fg2, &n);
    for (steps = 0; steps < n; ++steps)
    {
      scanf(" %lf %lf %lf", &walk[steps].b, &walk[steps].e, &walk[steps].w);
      walk[steps].length = walk[steps].e - walk[steps].b;
      m -= walk[steps].e - walk[steps].b;
    }

    qsort(walk, n, sizeof(struct Walk), cmp);
    time = 0;
    if (m >= (fg2 * r))
    {
      time += fg2;
      m -= fg2 * r;
      time += m / arr;
      fg2 = 0;
    }
    else
    {
      time += m / r;
      fg2 -= m / r;
    }

    for (steps = 0; steps < n; ++steps)
    {
      if (fg2 > 0.0)
      {
        if (walk[steps].length >= ((walk[steps].w + r) * fg2))
        {
          time += fg2;
          walk[steps].length -= (walk[steps].w + r) * fg2;
          time += walk[steps].length / (walk[steps].w + arr);
          fg2 = 0;
        }
        else
        {
          time += walk[steps].length / (walk[steps].w + r);
          fg2 -= walk[steps].length / (walk[steps].w + r);
        }

      }
      else
      {
        time += ((double) walk[steps].length) / ((double) (walk[steps].w + arr));
      }

    }

    printf("Case #%d: %lf\n", t, time);
  }

  return 0;
}


