#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct edge_t
{
  int b;
  struct edge_t *next;
} EDGE;
EDGE e[2008];
EDGE *start[1008];
int en;
int used[1008];
int d[1008][1008];
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int comp(const void *p, const void *q)
{
  int first_iteration;
  return (*((int *) q)) - (*((int *) p));
}

void add_edge(int A, int B)
{
  int first_iteration;
  e[en].b = B;
  e[en].next = start[A];
  start[A] = &e[en++];
}

int dfs(int v, int k)
{
  int first_iteration;
  EDGE *p;
  int cnt = 0;
  used[v] = 1;
  for (p = start[v]; p != 0; p = p->next)
  {
    if (used[p->b])
      continue;

    d[k][cnt++] = dfs(p->b, k + 1);
  }

  if (cnt <= 1)
    return 1;

  new_qsort(d[k], cnt, 4, comp);
  return (1 + d[k][0]) + d[k][1];
}

int main()
{
  int first_iteration;
  int tt;
  int ttt;
  int n;
  int i;
  int a;
  int b;
  int tmp;
  int res;
  scanf("%d", &tt);
  for (ttt = 1; ttt <= tt; ttt++)
  {
    scanf("%d", &n);
    res = 0;
    en = 0;
    for (i = 1; i <= n; i++)
      start[i] = 0;

    for (i = 0; i < (n - 1); i++)
    {
      scanf("%d%d", &a, &b);
      add_edge(a, b);
      add_edge(b, a);
    }

    for (i = 1; i <= n; i++)
    {
      memset(used, 0, sizeof(used));
      tmp = dfs(i, 0);
      if (res < tmp)
        res = tmp;

    }

    printf("Case #%d: %d\n", ttt, n - res);
  }

  return 0;
}

void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}


