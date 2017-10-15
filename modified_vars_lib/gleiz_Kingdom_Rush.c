#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
int lst[640] = {0};
int allTotal[1 << 21] = {0};
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int comp(const void *t, const void *xdrs)
{
  return (*((int *) t)) - (*((int *) xdrs));
}

int print(int mask)
{
  int id = 0;
  int first = 1;
  while (mask)
  {
    if (mask & 1)
    {
      if (first)
      {
        printf("%d", lst[id]);
        first = 0;
      }
      else
      {
        printf(" %d", lst[id]);
      }

    }

    mask /= 2;
    id++;
  }

  printf("\n");
  return 0;
}

int check(int cas, int num, int msk, int width)
{
  for (int acount = 1; acount < (1 << width); acount++)
  {
    int mask = acount;
    int sNum = 0;
    int id = 0;
    int kkk = msk;
    while (mask)
    {
      if (((mask & 1) != 0) && ((kkk & 1) == 0))
      {
        sNum += lst[id];
      }

      mask /= 2;
      kkk /= 2;
      id++;
    }

    if (sNum == num)
    {
      printf("Case #%d:\n", cas);
      print(acount);
      print(msk);
      return 1;
    }

  }

  return 0;
}

int Main(int argc, char *argv[])
{
  int tc = 0;
  int width = 0;
  scanf("%d", &tc);
  for (int cas = 1; cas <= tc; cas++)
  {
    int total = 0;
    scanf("%d", &width);
    for (int acount = 0; acount < width; acount++)
    {
      scanf("%d", &lst[acount]);
      total += lst[acount];
    }

    for (int sNum = 1; sNum < (1 << width); sNum++)
    {
      int mask = sNum;
      int id = 0;
      int num = 0;
      while (mask)
      {
        if (mask & 1)
        {
          num += lst[id];
        }

        id++;
        mask /= 2;
      }

      allTotal[sNum] = num;
    }

    new_qsort(allTotal, 1 << width, sizeof(int), comp);
    int cont = 1;
    for (int sNum = 1; (sNum < (1 << width)) && (cont == 1); sNum++)
    {
      int mask = sNum;
      int id = 0;
      int num = 0;
      while (mask)
      {
        if (mask & 1)
        {
          num += lst[id];
        }

        id++;
        mask /= 2;
      }

      if (bsearch(&num, allTotal, 1 << width, sizeof(int), comp) != 0)
      {
        int ret = check(cas, num, sNum, width);
        if (ret == 1)
          cont = 0;

      }

    }

    if (cont == 1)
    {
      printf("Case #%d:\n", cas);
      printf("Impossible\n");
    }

  }

  return 0;
}



void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}