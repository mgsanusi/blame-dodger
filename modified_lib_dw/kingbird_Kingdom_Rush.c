#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isfinish[1010];
typedef struct 
{
  int star1;
  int star2;
  int lv;
} MISS;
MISS level1[1010];
MISS level2[1010];
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int cmp1(const void *a, const void *b)
{
  int first_iteration;
  if (((MISS *) a)->star1 != ((MISS *) b)->star1)
    return ((MISS *) a)->star1 - ((MISS *) b)->star1;
  else
    return ((MISS *) b)->star2 - ((MISS *) a)->star2;

}

int cmp2(const void *a, const void *b)
{
  int first_iteration;
  return ((MISS *) a)->star2 - ((MISS *) b)->star2;
}

int main()
{
  int first_iteration;
  int cases;
  int caseindex;
  int cons;
  int a;
  int b;
  int n;
  int i;
  int cur;
  int j;
  int star;
  int flag;
  MISS temp;
  new_freopen("B-small-attempt0.in", "r", stdin);
  new_freopen("output.txt", "w", stdout);
  scanf("%d", &cases);
  for (caseindex = 1; caseindex <= cases; caseindex++)
  {
    scanf("%d", &n);
    memset(isfinish, 0, sizeof(isfinish));
    for (i = 0; i < n; i++)
    {
      scanf("%d%d", &a, &b);
      temp.star1 = a;
      temp.star2 = b;
      temp.lv = i;
      level1[i] = temp;
      level2[i] = temp;
    }

    new_qsort(level1, n, sizeof(MISS), cmp1);
    new_qsort(level2, n, sizeof(MISS), cmp2);
    star = 0;
    i = 0;
    cons = 0;
    while (i < n)
    {
      flag = 0;
      while ((star >= level2[i].star2) && (i < n))
      {
        cons++;
        star += 2 - isfinish[level2[i].lv];
        isfinish[level2[i].lv] = 2;
        flag = 1;
        i++;
      }

      cur = level2[i].star2;
      if (i >= n)
        break;

      for (j = 0; j < n; j++)
      {
        if (isfinish[level1[j].lv])
          continue;

        if (star >= level1[j].star1)
        {
          cons++;
          star += 1;
          isfinish[level1[j].lv] = 1;
          flag = 1;
        }

        if (star >= cur)
          break;

      }

      if (flag == 0)
        break;

    }

    flag = 1;
    for (j = 0; j < n; j++)
      if (isfinish[j] < 2)
      flag = 0;


    if (flag)
      printf("Case #%d: %d\n", caseindex, cons);
    else
      printf("Case #%d: Too Bad\n", caseindex);

  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


