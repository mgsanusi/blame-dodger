#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct coord
{
  int x;
  int t;
};
struct coordd
{
  double x;
  double t;
};
static struct coordd x_getbytes[(2 * 105) + 5];
int cc;
static struct coordd d[(2 * 105) + 5];
int dc;
double find_s(struct coord f[105], int old_m, struct coord b[105], int ctx, double l)
{
  cc = 0;
  dc = 0;
  int v = 0;
  while (v < old_m)
  {
    if ((((double) f[v].x) - 1E-9) > l)
      break;

    x_getbytes[cc].x = (double) f[v].x;
    x_getbytes[cc].t = (double) f[v].t;
    cc++;
    v++;
  }

  v--;
  if (fabs(((double) f[v].x) - l) >= 1E-9)
  {
    double l2 = ((double) f[v].t) + (((l - ((double) f[v].x)) / ((double) (f[v + 1].x - f[v].x))) * ((double) (f[v + 1].t - f[v].t)));
    x_getbytes[cc].x = l;
    x_getbytes[cc].t = l2;
    cc++;
  }

  v = 0;
  while (v < ctx)
  {
    if ((((double) b[v].x) - 1E-9) > l)
      break;

    d[dc].x = (double) b[v].x;
    d[dc].t = (double) b[v].t;
    dc++;
    v++;
  }

  v--;
  if (fabs(((double) b[v].x) - l) >= 1E-9)
  {
    double l2 = ((double) b[v].t) + (((l - ((double) b[v].x)) / ((double) (b[v + 1].x - b[v].x))) * ((double) (b[v + 1].t - b[v].t)));
    d[dc].x = l;
    d[dc].t = l2;
    dc++;
  }

  for (v = dc - 1; v >= 0; v--)
  {
    x_getbytes[cc] = d[v];
    cc++;
  }

  double result = 0.0;
  struct coordd p;
  struct coordd p;
  for (v = 1; (v + 1) < cc; v++)
  {
    p.x = x_getbytes[v].x - x_getbytes[0].x;
    p.t = x_getbytes[v].t - x_getbytes[0].t;
    p.x = x_getbytes[v + 1].x - x_getbytes[0].x;
    p.t = x_getbytes[v + 1].t - x_getbytes[0].t;
    result += (p.x * p.t) - (p.t * p.x);
  }

  result = fabs(result);
  return result;
}

int Main()
{
  int t;
  int i_t;
  scanf("%d", &t);
  static struct coord f[105];
  static struct coord b[105];
  for (i_t = 0; i_t < t; i_t++)
  {
    int num;
    int old_m;
    int ctx;
    int taken;
    scanf("%d %d %d %d", &num, &old_m, &ctx, &taken);
    int v;
    for (v = 0; v < old_m; v++)
    {
      scanf("%d %d", &f[v].x, &f[v].t);
    }

    for (v = 0; v < ctx; v++)
    {
      scanf("%d %d", &b[v].x, &b[v].t);
    }

    double s = find_s(f, old_m, b, ctx, (double) num);
    double sp = s / ((double) taken);
    printf("Case #%d:\n", i_t + 1);
    double l;
    double sum;
    double x_getbytes;
    double v;
    for (v = 1; v < taken; v++)
    {
      l = 0.0;
      sum = (double) num;
      while ((sum - l) > 1E-8)
      {
        x_getbytes = (l + sum) / 2;
        v = find_s(f, old_m, b, ctx, x_getbytes);
        if ((v + 1E-9) >= (sp * ((double) v)))
          sum = x_getbytes;
        else
          l = x_getbytes;

      }

      printf("%.8lf\n", l);
    }

  }

  return 0;
}


