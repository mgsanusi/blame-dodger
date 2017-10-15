#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
long double x;
long double k;
long double k;
long double len;
long double stack_num;
long double time;
int tmp_n;
ssize_t new_read (int fd, void *buf, size_t count);
double new_sqrt (double x);
void
new_read ()
{
  int j;
  long a;
  long b;
  long s;
  long d;
  long outlets;
  long ru;
  x = (k = (k = (len = (stack_num = (time = 0)))));
  scanf ("%d", &tmp_n);
  for (j = 0; j < tmp_n; j++)
    {
      scanf ("%d%d%d%d%d%d", &a, &b, &s, &d, &outlets, &ru);
      x += a;
      k += b;
      k += s;
      len += d;
      stack_num += outlets;
      time += ru;
    }
  x /= tmp_n;
  k /= tmp_n;
  k /= tmp_n;
  len /= tmp_n;
  stack_num /= tmp_n;
  time /= tmp_n;
}

long double
get_time ()
{
  if ((((len * len) + (stack_num * stack_num)) + (time * time)) == 0)
    {
      return 0;
    }
  return (-(((len * x) + (stack_num * k)) + (time * k))) /
    (((len * len) + (stack_num * stack_num)) + (time * time));
}

long double
dist (long double l)
{
  return
    new_sqrt (((((len * l) + x) * ((len * l) + x)) +
	       (((stack_num * l) + k) * ((stack_num * l) + k))) +
	      (((time * l) + k) * ((time * l) + k)));
}

void
single_case ()
{
  long double l;
  new_read ();
  l = get_time ();
  if (l < 0)
    l = 0;
  printf ("%0.8Lf %0.8Lf\n", dist (l), l);
}

int
Main ()
{
  int s;
  int j;
  scanf ("%d\n", &s);
  for (j = 1; j <= s; j++)
    {
      printf ("Case #%d: ", j);
      single_case ();
    }
  return 0;
}

ssize_t
new_read (int fd, void *buf, size_t count)
{
  return read (fd, buf, count);
}

double
new_sqrt (double x)
{
  return sqrt (x);
}
