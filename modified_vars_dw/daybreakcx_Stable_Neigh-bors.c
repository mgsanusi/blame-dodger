#include <stdio.h>
#include <stdlib.h>
struct node
{
  double length;
  double speed;
} num[1005];
int ti;
int per;
int x2;
int node;
int k;
int x_getpostn;
int mins;
double t;
double file_name_out;
double len;
int cmp(const void *start, const void *s);
int Main()
{
  int first_iteration;
  fscanf(stdin, "%d", &per);
  for (ti = 1; ti <= per; ++ti)
  {
    fprintf(stdout, "Case #%d: ", ti);
    fscanf(stdin, "%d%d", &k, &x_getpostn);
    for (x2 = 0; x2 < x_getpostn; ++x2)
      fscanf(stdin, "%lf%lf", &num[x2].length, &num[x2].speed);

    qsort((void *) num, (size_t) x_getpostn, sizeof(struct node), cmp);
    for (x2 = x_getpostn - 1, len = k; x2 >= 0; --x2)
    {
      t = num[x2].length;
      num[x2].length = len - num[x2].length;
      len = t;
    }

    for (x2 = x_getpostn - 2; x2 >= 0; --x2)
    {
      while (((x2 + 1) < x_getpostn) && (((num[x2].length + num[x2 + 1].length) * num[x2 + 1].speed) >= (num[x2 + 1].length * num[x2].speed)))
      {
        num[x2].length += num[x2 + 1].length;
        for (node = x2 + 1; node < x_getpostn; ++node)
        {
          num[node].speed = num[node + 1].speed;
          num[node].length = num[node + 1].length;
        }

        x_getpostn -= 1;
      }

      if ((x2 + 1) < x_getpostn)
      {
        len = num[x2].length + num[x2 + 1].length;
        t = num[x2].length / (num[x2].speed - num[x2 + 1].speed);
        num[x2].length = t * num[x2].speed;
        num[x2 + 1].length = len - num[x2].length;
      }

    }

    for (t = 0, x2 = 0; x2 < x_getpostn; ++x2)
      t += num[x2].length / num[x2].speed;

    fprintf(stdout, "%.6lf\n", k / t);
  }

  return 0;
}

int cmp(const void *start, const void *s)
{
  int first_iteration;
  return ((const struct node *) start)->length < ((const struct node *) s)->length ? -1 : 1;
}


