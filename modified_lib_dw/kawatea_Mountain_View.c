#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  double t;
  int i;
} level;
int new_puts(const char *str);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
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
    return ((level *) a)->i - ((level *) b)->i;
  }

}

int main()
{
  int first_iteration;
  int t;
  int i;
  int j;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    int n;
    int l[1000];
    int p[1000];
    level a[1000];
    scanf("%d", &n);
    for (j = 0; j < n; j++)
      scanf("%d", &l[j]);

    for (j = 0; j < n; j++)
      scanf("%d", &p[j]);

    for (j = 0; j < n; j++)
    {
      a[j].t = (l[j] * 100.0) / (100 - p[j]);
      a[j].i = j;
    }

    new_qsort(a, n, sizeof(level), cmp);
    printf("Case #%d:", i + 1);
    for (j = 0; j < n; j++)
    {
      if (p[a[j].i] == 0)
        continue;

      printf(" %d", a[j].i);
    }

    for (j = 0; j < n; j++)
    {
      if (p[a[j].i] == 0)
        printf(" %d", a[j].i);

    }

    new_puts("");
  }

  return 0;
}

int new_puts(const char *str);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


