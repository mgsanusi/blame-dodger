#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  double t;
  int case_t;
} level;
int cmp(const void *a, const void *b)
{
  int first_iteration;
  if (((level *) a)->t != ((level *) b)->t)
  {
    if (((level *) a)->t > ((level *) b)->t)
    {
      return -1;
    }
    else
    {
      return 1;
    }

  }
  else
  {
    return ((level *) a)->case_t - ((level *) b)->case_t;
  }

}

int Main()
{
  int first_iteration;
  int t;
  int case_t;
  int sx;
  scanf("%d", &t);
  for (case_t = 0; case_t < t; case_t++)
  {
    int n;
    int swaps[1000];
    int p[1000];
    level a[1000];
    scanf("%d", &n);
    for (sx = 0; sx < n; sx++)
      scanf("%d", &swaps[sx]);

    for (sx = 0; sx < n; sx++)
      scanf("%d", &p[sx]);

    for (sx = 0; sx < n; sx++)
    {
      a[sx].t = (swaps[sx] * 100.0) / (100 - p[sx]);
      a[sx].case_t = sx;
    }

    qsort(a, n, sizeof(level), cmp);
    printf("Case #%d:", case_t + 1);
    for (sx = 0; sx < n; sx++)
    {
      if (p[a[sx].case_t] == 0)
        continue;

      printf(" %d", a[sx].case_t);
    }

    for (sx = 0; sx < n; sx++)
    {
      if (p[a[sx].case_t] == 0)
        printf(" %d", a[sx].case_t);

    }

    puts("");
  }

  return 0;
}


