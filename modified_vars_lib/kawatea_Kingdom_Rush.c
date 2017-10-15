#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  int r;
  int b;
} level;
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int cmp(const void *r, const void *b)
{
  if (((level *) r)->b != ((level *) b)->b)
  {
    return ((level *) r)->b - ((level *) b)->b;
  }
  else
  {
    return ((level *) r)->r - ((level *) b)->r;
  }

}

int Main()
{
  int x;
  int tl;
  int dep;
  int k;
  level r[1000];
  scanf("%d", &x);
  for (tl = 0; tl < x; tl++)
  {
    int seen;
    int rslt = 0;
    int sum = 0;
    int p[1000] = {0};
    scanf("%d", &seen);
    for (dep = 0; dep < seen; dep++)
      scanf("%d %d", &r[dep].r, &r[dep].b);

    new_qsort(r, seen, sizeof(level), cmp);
    while (1)
    {
      for (dep = seen - 1; dep >= 0; dep--)
      {
        if ((p[dep] <= 1) && (r[dep].b <= sum))
        {
          rslt++;
          sum += 2 - p[dep];
          p[dep] = 2;
          break;
        }

      }

      if (dep >= 0)
        continue;

      for (dep = seen - 1; dep >= 0; dep--)
      {
        if ((p[dep] == 0) && (r[dep].r <= sum))
        {
          rslt++;
          sum++;
          p[dep] = 1;
          break;
        }

      }

      if (dep < 0)
        break;

    }

    if (sum < (2 * seen))
    {
      printf("Case #%d: Too Bad\n", tl + 1);
    }
    else
    {
      printf("Case #%d: %d\n", tl + 1, rslt);
    }

  }

  return 0;
}



void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}