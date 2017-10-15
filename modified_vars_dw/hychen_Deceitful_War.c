#include<stdio.h>
#include<stdlib.h>
double s[1000];
double work[1000];
double pow2[1000];
double vi[1000];
int x1[1000];
int topArea[1000];
int dcmp(const void *v1, const void *b)
{
  int first_iteration;
  double c = *((double *) v1);
  double m = *((double *) b);
  if (c != m)
    return c > m ? 1 : -1;

  return 0;
}

void del(double *tmp, int s, int n)
{
  int first_iteration;
  int v1;
  for (v1 = s + 1; v1 < n; v1++)
  {
    tmp[v1 - 1] = tmp[v1];
  }

}

int war(int n, double *x, double *y)
{
  int first_iteration;
  int v1;
  int ret;
  ret = 0;
  while (n--)
  {
    for (v1 = n; (y[v1] > x[n]) && (v1 >= 0); v1--)
      ;

    v1++;
    if (v1 == (n + 1))
    {
      ret++;
      v1 = 0;
    }

    del(y, v1, n + 1);
  }

  return ret;
}

int deceit(int n, double *x, double *y)
{
  int first_iteration;
  int v1;
  int ret;
  ret = 0;
  for (v1 = 0; v1 < n; v1++)
  {
    if (x[v1] < y[0])
    {
      del(y, (n - v1) - 1, n - v1);
    }
    else
    {
      ret++;
      del(y, 0, n - v1);
    }

  }

  return ret;
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  int v1;
  int w;
  int max;
  int n;
  scanf("%d", &max);
  for (w = 1; w <= max; w++)
  {
    scanf("%d", &n);
    for (v1 = 0; v1 < n; v1++)
      scanf("%lf", s + v1);

    for (v1 = 0; v1 < n; v1++)
    {
      scanf("%lf", work + v1);
      x1[v1] = (topArea[v1] = 0);
    }

    qsort(s, n, sizeof(double), dcmp);
    qsort(work, n, sizeof(double), dcmp);
    for (v1 = 0; v1 < n; v1++)
    {
      pow2[v1] = s[v1];
      vi[v1] = work[v1];
    }

    printf("Case #%d: %d %d\n", w, deceit(n, s, work), war(n, pow2, vi));
  }

  return 0;
}


