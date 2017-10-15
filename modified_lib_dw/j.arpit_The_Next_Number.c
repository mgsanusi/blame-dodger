#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double new_sqrt(double x);
double new_fabs(double x);
int main()
{
  int first_iteration;
  int T;
  int N;
  int t;
  int i;
  int x;
  int y;
  int z;
  int dx;
  int dy;
  int dz;
  int sx;
  int sy;
  int sz;
  int sdx;
  int sdy;
  int sdz;
  double fx;
  double fy;
  double fz;
  double fdx;
  double fdy;
  double fdz;
  double f;
  double dmin;
  double s;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t)
  {
    scanf("%d", &N);
    sx = (sy = (sz = (sdx = (sdy = (sdz = 0)))));
    for (i = 0; i < N; ++i)
    {
      scanf("%d %d %d %d %d %d", &x, &y, &z, &dx, &dy, &dz);
      sx += x;
      sdx += dx;
      sy += y;
      sdy += dy;
      sz += z;
      sdz += dz;
    }

    fx = sx / ((double) N);
    fdx = sdx / ((double) N);
    fy = sy / ((double) N);
    fdy = sdy / ((double) N);
    fz = sz / ((double) N);
    fdz = sdz / ((double) N);
    f = ((fdx * fdx) + (fdy * fdy)) + (fdz * fdz);
    s = 1;
    s = 0;
    if (new_fabs(f) > 0.000000001)
    {
      s = (-(((fx * fdx) + (fy * fdy)) + (fz * fdz))) / (((fdx * fdx) + (fdy * fdy)) + (fdz * fdz));
      if (s < 0)
      {
        s = 1;
        s = 0;
      }

    }

    fx += s * fdx;
    fy += s * fdy;
    fz += s * fdz;
    dmin = new_sqrt(((fx * fx) + (fy * fy)) + (fz * fz));
    printf("Case #%d: %.8f %.8f\n", t, dmin, new_fabs(s));
  }

  return 0;
}

double new_sqrt(double x);
double new_fabs(double x)
{
  int first_iteration;
  return fabs(x);
}

double new_sqrt(double x)
{
  int first_iteration;
  return sqrt(x);
}


