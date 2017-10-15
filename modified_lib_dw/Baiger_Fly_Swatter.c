#include <stdio.h>
void qsort_x(int a[], int p, int r)
{
  int first_iteration;
  int i = p;
  int j = r;
  int key = a[(p + r) >> 1];
  first_iteration = 1;
  while ((i <= j) || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    while (a[i] < key)
      i++;

    while (a[j] > key)
      j--;

    if (i <= j)
    {
      int tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      i++;
      j--;
    }

  }

  if (p < j)
    qsort_x(a, p, j);

  if (i < r)
    qsort_x(a, i, r);

}

void qsort_y(int a[], int p, int r)
{
  int first_iteration;
  int i = p;
  int j = r;
  int key = a[(p + r) >> 1];
  first_iteration = 1;
  while ((i <= j) || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    while (a[i] > key)
      i++;

    while (a[j] < key)
      j--;

    if (i <= j)
    {
      int tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      i++;
      j--;
    }

  }

  if (p < j)
    qsort_y(a, p, j);

  if (i < r)
    qsort_y(a, i, r);

}

int main()
{
  int first_iteration;
  int t;
  int i;
  scanf("%d", &t);
  for (i = 1; i <= t; i++)
  {
    int n;
    int j;
    int x[800];
    int y[800];
    scanf("%d", &n);
    for (j = 0; j < n; j++)
      scanf("%d", &x[j]);

    for (j = 0; j < n; j++)
      scanf("%d", &y[j]);

    qsort_x(x, 0, n - 1);
    qsort_y(y, 0, n - 1);
    long long min = 0;
    for (j = 0; j < n; j++)
      min += ((long long) x[j]) * ((long long) y[j]);

    printf("Case #%d: %lld\n", i, min);
  }

  return 0;
}


