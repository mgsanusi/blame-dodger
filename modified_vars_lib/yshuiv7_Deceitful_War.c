#include<stdio.h>
#include <string.h>

#include <stddef.h>
double n[1000];
double close[1000];
void * new_memset(void *ptr, int value, size_t num);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int cmp(const void *r, const void *b)
{
  double fpO = *((const double *) r);
  double y = *((const double *) b);
  return fpO > y ? 1 : fpO < y ? -1 : 0;
}

int t[1000];
int flag[1000];
int match[1000];
int rslt;
int bimatch(int close)
{
  int g;
  for (g = t[close]; g >= 0; g--)
  {
    if (flag[g])
      continue;

    flag[g] = 1;
    if ((match[g] == (-1)) || bimatch(match[g]))
    {
      match[g] = close;
      return 1;
    }

  }

  return 0;
}

int Main()
{
  int cases;
  int p;
  scanf("%d", &cases);
  for (p = 1; p <= cases; p++)
  {
    int sy;
    scanf("%d", &sy);
    int g;
    for (g = 0; g < sy; g++)
      scanf("%lf", n + g);

    for (g = 0; g < sy; g++)
      scanf("%lf", close + g);

    int tempI;
    int lk;
    int key;
    int aUse;
    tempI = (lk = 0);
    key = (aUse = sy - 1);
    new_qsort(n, sy, sizeof(double), cmp);
    new_qsort(close, sy, sizeof(double), cmp);
    int mMask = 0;
    new_memset(match, 255, sizeof(match));
    for (g = 0; g < sy; g++)
    {
      while ((close[mMask] < n[g]) && (mMask < sy))
        mMask++;

      t[g] = mMask - 1;
    }

    rslt = 0;
    for (g = 0; g < sy; g++)
    {
      new_memset(flag, 0, sizeof(flag));
      if (bimatch(g))
        rslt++;

    }

    int ans2 = 0;
    new_memset(flag, 0, sizeof(flag));
    for (g = 0; g < sy; g++)
    {
      mMask = t[g] + 1;
      for (; mMask < sy; mMask++)
        if (!flag[mMask])
        break;


      if (mMask < sy)
      {
        flag[mMask] = 1;
      }
      else
      {
        ans2++;
        flag[lk] = 1;
        lk++;
      }

    }

    printf("Case #%d: %d %d\n", p, rslt, ans2);
  }

  return 0;
}



void * new_memset(void *ptr, int value, size_t num);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}