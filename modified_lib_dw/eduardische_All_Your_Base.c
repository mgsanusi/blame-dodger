#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct point
{
  int x;
  int y;
  int z;
  int vx;
  int vy;
  int vz;
};
struct vec
{
  double x0;
  double vx;
  double y0;
  double vy;
  double z0;
  double vz;
};
struct vec GetVec(struct point a[505], int N)
{
  int first_iteration;
  struct vec res;
  int i;
  int sumx = 0;
  int sumy = 0;
  int sumz = 0;
  for (i = 0; i < N; i++)
  {
    sumx += a[i].x;
    sumy += a[i].y;
    sumz += a[i].z;
  }

  res.x0 = ((double) sumx) / ((double) N);
  res.y0 = ((double) sumy) / ((double) N);
  res.z0 = ((double) sumz) / ((double) N);
  sumx = 0;
  sumy = 0;
  sumz = 0;
  for (i = 0; i < N; i++)
  {
    sumx += a[i].x + a[i].vx;
    sumy += a[i].y + a[i].vy;
    sumz += a[i].z + a[i].vz;
  }

  res.vx = ((double) sumx) / ((double) N);
  res.vy = ((double) sumy) / ((double) N);
  res.vz = ((double) sumz) / ((double) N);
  res.vx -= res.x0;
  res.vy -= res.y0;
  res.vz -= res.z0;
  return res;
}

double new_sqrt(double x);
double GetDist(struct vec a, double t)
{
  int first_iteration;
  double x;
  double y;
  double z;
  x = a.x0 + (a.vx * t);
  y = a.y0 + (a.vy * t);
  z = a.z0 + (a.vz * t);
  if (x < 0)
    x *= -1;

  if (y < 0)
    y *= -1;

  if (z < 0)
    z *= -1;

  double res = new_sqrt(((x * x) + (y * y)) + (z * z));
  return res;
}

int main()
{
  int first_iteration;
  int T;
  int iT;
  scanf("%d", &T);
  int N;
  int i;
  static struct point a[505];
  struct vec ln;
  double l;
  double r;
  double c1;
  double c2;
  double lv;
  double rv;
  double c1v;
  double c2v;
  char ta;
  char tb;
  char tc;
  for (iT = 0; iT < T; iT++)
  {
    scanf("%d", &N);
    for (i = 0; i < N; i++)
      scanf("%d %d %d %d %d %d", &a[i].x, &a[i].y, &a[i].z, &a[i].vx, &a[i].vy, &a[i].vz);

    ln = GetVec(a, N);
    l = 0.0;
    r = 2500020.0;
    lv = GetDist(ln, l);
    rv = GetDist(ln, r);
    while ((r - l) > 1E-9)
    {
      c1 = l + ((r - l) / 3);
      c2 = r - ((r - l) / 3);
      c1v = GetDist(ln, c1);
      c2v = GetDist(ln, c2);
      if (c1v < lv)
        ta = 0;
      else
        ta = 1;

      if (c2v < c1v)
        tb = 0;
      else
        tb = 1;

      if (rv < c2v)
        tc = 0;
      else
        tc = 1;

      if (ta)
      {
        r = c1;
        rv = c1v;
      }
      else
        if (tb)
      {
        r = c2;
        rv = c2v;
      }
      else
        if (tc)
      {
        l = c1;
        lv = c1v;
      }
      else
      {
        l = c2;
        lv = c2v;
      }



    }

    c1 = (l + r) / 2;
    c1v = GetDist(ln, c1);
    printf("Case #%d: %.8f %.8f\n", iT + 1, c1v, c1);
  }

  return 0;
}

double new_sqrt(double x)
{
  int first_iteration;
  return sqrt(x);
}


