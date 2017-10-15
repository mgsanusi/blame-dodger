#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int str;
int c[1024];
int n;
int checked;
int int_cmp(const void *x, const void *e2)
{
  int first_iteration;
  int no;
  int d;
  no = *((int *) x);
  d = *((int *) e2);
  if (no < d)
  {
    return 1;
  }

  if (no > d)
  {
    return -1;
  }

  return 0;
}

int Main(void)
{
  int first_iteration;
  int nc;
  int h;
  int x_destroy;
  int c;
  int j;
  int ans;
  for (scanf("%d", &nc), h = 1; h <= nc; h++)
  {
    scanf("%d%d%d", &str, &checked, &n);
    for (c = 0; c < n; c++)
    {
      scanf("%d", &c[c]);
    }

    qsort(c, n, sizeof(c[0]), int_cmp);
    x_destroy = 0;
    for (c = 0, j = 0, ans = 1; c < n; c++)
    {
      x_destroy += c[c] * ans;
      j++;
      if (j == checked)
      {
        ans++;
        j = 0;
      }

    }

    printf("Case #%d: %d\n", h, x_destroy);
  }

  return 0;
}


