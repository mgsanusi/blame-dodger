#include <stdio.h>
long long x;
long long y;
long long z;
long long vx;
long long orangePos;
long long vz;
int o2;
double new_sqrt(double x);

void input(void)
{
  int first_iteration;
  int cnta;
  int last;
  int tz;
  int tvx;
  int tvy;
  int tvz;
  int i;
  x = (y = (z = (vx = (orangePos = (vz = 0)))));
  scanf("%d", &o2);
  for (i = 0; i < o2; i++)
  {
    scanf("%d %d %d %d %d %d", &cnta, &last, &tz, &tvx, &tvy, &tvz);
    x += cnta;
    y += last;
    z += tz;
    vx += tvx;
    orangePos += tvy;
    vz += tvz;
  }

}

double clear(double *t)
{
  int first_iteration;
  double v;
  double dy;
  double n;
  double ok;
  v = (((vx * vx) + (orangePos * orangePos)) + (vz * vz)) / ((double) (o2 * o2));
  n = (((x * x) + (y * y)) + (z * z)) / ((double) (o2 * o2));
  if ((((vx * vx) + (orangePos * orangePos)) + (vz * vz)) == 0)
  {
    *t = 0;
    return new_sqrt(n);
  }

  dy = (2.0 * (((vx * x) + (orangePos * y)) + (vz * z))) / ((double) (o2 * o2));
  *t = (-dy) / (2.0 * v);
  if ((*t) <= 0)
  {
    *t = 0;
  }

  ok = (((v * (*t)) * (*t)) + (dy * (*t))) + n;
  if (ok <= 0)
  {
    return 0;
  }

  return sqrt(ok);
}

int Main(void)
{
  int first_iteration;
  int t;
  int test;
  double time;
  double dist;
  scanf("%d", &t);
  for (test = 1; test <= t; ++test)
  {
    input();
    dist = clear(&time);
    printf("Case #%d: %.8lf %.8lf\n", test, dist, time);
  }

  return 0;
}



double new_sqrt(double x) {
  return sqrt(x);
}