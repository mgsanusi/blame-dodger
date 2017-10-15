#include <stdio.h>
#include <stdlib.h>
struct node
{
  double length;
  double speed;
} a[1005];
int ti;
int tn;
int i;
int j;
int d;
int n;
int mins;
double t;
double v;
double len;
int cmp(const void *x, const void *y);
int main()
{
  int first_iteration;
  fscanf(stdin, "%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
  {
    fprintf(stdout, "Case #%d: ", ti);
    fscanf(stdin, "%d%d", &d, &n);
    for (i = 0; i < n; ++i)
      fscanf(stdin, "%lf%lf", &a[i].length, &a[i].speed);

    qsort((void *) a, (size_t) n, sizeof(struct node), cmp);
    for (i = n - 1, len = d; i >= 0; --i)
    {
      t = a[i].length;
      a[i].length = len - a[i].length;
      len = t;
    }

    for (i = n - 2; i >= 0; --i)
    {
      while (((i + 1) < n) && (((a[i].length + a[i + 1].length) * a[i + 1].speed) >= (a[i + 1].length * a[i].speed)))
      {
        a[i].length += a[i + 1].length;
        for (j = i + 1; j < n; ++j)
        {
          a[j].speed = a[j + 1].speed;
          a[j].length = a[j + 1].length;
        }

        n -= 1;
      }

      if ((i + 1) < n)
      {
        len = a[i].length + a[i + 1].length;
        t = a[i].length / (a[i].speed - a[i + 1].speed);
        a[i].length = t * a[i].speed;
        a[i + 1].length = len - a[i].length;
      }

    }

    for (t = 0, i = 0; i < n; ++i)
      t += a[i].length / a[i].speed;

    fprintf(stdout, "%.6lf\n", d / t);
  }

  return 0;
}

int cmp(const void *x, const void *y)
{
  int first_iteration;
  return ((const struct node *) x)->length < ((const struct node *) y)->length ? -1 : 1;
}


