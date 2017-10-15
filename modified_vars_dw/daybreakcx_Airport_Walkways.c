#include <stdio.h>
#include <stdlib.h>
struct node
{
  int d;
  int x2;
  int pattern;
} d[3000];
struct node
{
  int d;
  int x2;
  int pattern;
} b[2000];
int count;
int ti;
int cases;
int n;
int c;
int v;
int sum;
int l;
double result;
double x2;
double envp;
int cmp(const void *cmps, const void *cmpt)
{
  int first_iteration;
  struct node *l = cmps;
  struct node *y = cmpt;
  return l->pattern < y->pattern ? -1 : 1;
}

int Main()
{
  int first_iteration;
  scanf("%d", &count);
  for (ti = 1; ti <= count; ++ti)
  {
    printf("Case #%d: ", ti);
    scanf("%d%d%d%lf%d", &l, &v, &sum, &x2, &n);
    for (cases = 0; cases < n; ++cases)
      scanf("%d%d%d", &d[cases].d, &d[cases].x2, &d[cases].pattern);

    for (cases = (c = 0); cases < n; ++cases)
      if (((!cases) && d[cases].d) || (cases && (d[cases].d > d[cases - 1].x2)))
    {
      if (cases)
        b[c].d = d[cases - 1].x2;
      else
        b[c].d = 0;

      b[c].x2 = d[cases].d;
      b[c++].pattern = 0;
    }


    if (d[n - 1].x2 < l)
    {
      b[c].d = d[n - 1].x2;
      b[c].x2 = l;
      b[c++].pattern = 0;
    }

    for (cases = 0; cases < c; ++cases)
      d[n++] = b[cases];

    qsort(d, n, sizeof(d[0]), cmp);
    for (result = (cases = 0); cases < n; ++cases)
      if ((x2 > 0) && (sum > v))
    {
      if ((x2 * (sum + d[cases].pattern)) >= (d[cases].x2 - d[cases].d))
      {
        envp = ((double) (d[cases].x2 - d[cases].d)) / (sum + d[cases].pattern);
        x2 -= envp;
        result += envp;
      }
      else
      {
        result += (((double) ((d[cases].x2 - d[cases].d) - (x2 * (sum + d[cases].pattern)))) / (v + d[cases].pattern)) + x2;
        x2 = -1;
      }

    }
    else
      result += ((double) (d[cases].x2 - d[cases].d)) / (v + d[cases].pattern);


    printf("%.6lf\n", result);
  }

  return 0;
}


