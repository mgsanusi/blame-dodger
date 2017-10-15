#include <stdio.h>
#include <stdlib.h>
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int compare(const void *f, const void *data2)
{
  return (*((int *) f)) - (*((int *) data2));
}

int Main(void)
{
  int tn;
  int rd;
  int t;
  scanf("%d", &t);
  for (tn = 1; tn <= t; tn++)
  {
    int n;
    int x;
    int s[10000];
    int l;
    int r;
    int rslt;
    scanf("%d %d", &n, &x);
    for (rd = 0; rd < n; rd++)
      scanf("%d", s + rd);

    new_qsort(s, n, sizeof(int), &compare);
    l = 0;
    r = n - 1;
    rslt = 0;
    while (l <= r)
      if ((s[l] + s[r]) <= x)
    {
      l++;
      r--;
      rslt++;
    }
    else
    {
      r--;
      rslt++;
    }


    printf("Case #%d: %d\n", tn, rslt);
  }

  return 0;
}



void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}