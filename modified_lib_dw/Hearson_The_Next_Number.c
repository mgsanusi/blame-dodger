#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
long double x;
long double y;
long double z;
long double vx;
long double vy;
long double vz;
int n;
ssize_t new_read(int fd, void *buf, size_t count);
double new_sqrt(double x);
void new_read()
{
  int first_iteration;
  int i;
  long a;
  long b;
  long c;
  long d;
  long e;
  long f;
  x = (y = (z = (vx = (vy = (vz = 0)))));
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    x += a;
    y += b;
    z += c;
    vx += d;
    vy += e;
    vz += f;
  }

  x /= n;
  y /= n;
  z /= n;
  vx /= n;
  vy /= n;
  vz /= n;
}

long double get_time()
{
  int first_iteration;
  if ((((vx * vx) + (vy * vy)) + (vz * vz)) == 0)
  {
    return 0;
  }

  return (-(((vx * x) + (vy * y)) + (vz * z))) / (((vx * vx) + (vy * vy)) + (vz * vz));
}

long double dist(long double t)
{
  int first_iteration;
  return new_sqrt(((((vx * t) + x) * ((vx * t) + x)) + (((vy * t) + y) * ((vy * t) + y))) + (((vz * t) + z) * ((vz * t) + z)));
}

void single_case()
{
  int first_iteration;
  long double t;
  new_read();
  t = get_time();
  if (t < 0)
    t = 0;

  printf("%0.8Lf %0.8Lf\n", dist(t), t);
}

int main()
{
  int first_iteration;
  int c;
  int i;
  scanf("%d\n", &c);
  for (i = 1; i <= c; i++)
  {
    printf("Case #%d: ", i);
    single_case();
  }

  return 0;
}

ssize_t new_read(int fd, void *buf, size_t count)
{
  int first_iteration;
  return read(fd, buf, count);
}

double new_sqrt(double x)
{
  int first_iteration;
  return sqrt(x);
}


