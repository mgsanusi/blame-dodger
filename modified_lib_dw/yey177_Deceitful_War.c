#include <stdio.h>
#include <stdlib.h>
double a[1008];
double b[1008];
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int comp(const void *_p, const void *_q)
{
  int first_iteration;
  double p = *((double *) _p);
  double q = *((double *) _q);
  if (p < q)
    return -1;

  if (p > q)
    return 1;

  return 0;
}

int main()
{
  int first_iteration;
  int t;
  int c;
  int n;
  int i;
  int j;
  int cnt;
  int r;
  scanf("%d", &t);
  for (c = 1; c <= t; c++)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%lf", &a[i]);

    a[n] = 0.0;
    a[n + 1] = 1.0;
    for (i = 0; i < n; i++)
      scanf("%lf", &b[i]);

    b[n] = 0.0;
    b[n + 1] = 1.0;
    new_qsort(a, n + 2, sizeof(double), comp);
    new_qsort(b, n + 2, sizeof(double), comp);
    i = (j = 1);
    cnt = (r = 0);
    while ((i <= n) || (j <= n))
    {
      if (a[i] > b[j])
      {
        cnt++;
        j++;
      }
      else
      {
        if (cnt > 0)
        {
          r++;
          cnt--;
        }

        i++;
      }

    }

    printf("Case #%d: %d ", c, r);
    i = (j = n);
    cnt = (r = 0);
    while ((i > 0) && (j > 0))
    {
      if (a[i] > b[j])
      {
        if (cnt == 0)
          r++;
        else
          cnt--;

        i--;
      }
      else
      {
        cnt++;
        j--;
      }

    }

    printf("%d\n", r);
  }

  return 0;
}

void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}


