#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int cmp(const void *a, const void *b)
{
  int first_iteration;
  return (*((int *) a)) - (*((int *) b));
}

int num[1234] = {0};
int next[1234] = {0};
int rslt;
int a;
int n;
void dfs(int p, int now, int sum)
{
  int first_iteration;
  int m;
  if (now > n)
  {
    if (sum < rslt)
      rslt = sum;

    return;
  }

  if (num[now] < p)
  {
    dfs(p + num[now], now + 1, sum);
    return;
  }
  else
  {
    dfs(p, now + 1, sum + 1);
    for (m = 0; (num[now] >= p) && (p > 1); ++m)
    {
      p += p - 1;
    }

    if (num[now] < p)
    {
      dfs(p + num[now], now + 1, sum + m);
    }

  }

}

int Main()
{
  int first_iteration;
  int x;
  int t;
  int i;
  scanf("%d", &x);
  for (t = 1; t <= x; ++t)
  {
    scanf("%d %d", &a, &n);
    for (i = 1; i <= n; ++i)
    {
      scanf("%d", &num[i]);
    }

    new_qsort(&num[1], n, sizeof(num[0]), cmp);
    rslt = 92345678;
    for (i = 1; (i <= n) && (num[i] < a); ++i)
    {
      a += num[i];
    }

    dfs(a, i, 0);
    printf("Case #%d: %d\n", t, rslt);
  }

  return 0;
}



void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}