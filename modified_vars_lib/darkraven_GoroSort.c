#include<stdio.h>
struct _
{
  int no;
  int id;
} down[1001];
int pa[1001];
int mark[1001];

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
static int cmp(const void *tmp, const void *b)
{
  return ((struct _ *) tmp)->no - ((struct _ *) b)->no;
}

int Main()
{
  int v;
  int k;
  scanf("%d", &v);
  int buttonPos;
  for (buttonPos = 1; buttonPos <= v; buttonPos++)
  {
    scanf("%d", &k);
    int gssCMaNotMech;
    for (gssCMaNotMech = 0; gssCMaNotMech < k; gssCMaNotMech++)
    {
      scanf("%d", pa + gssCMaNotMech);
      down[gssCMaNotMech].no = pa[gssCMaNotMech];
      down[gssCMaNotMech].id = gssCMaNotMech;
    }

    new_qsort(down, k, sizeof(struct _), cmp);
    for (gssCMaNotMech = 0; gssCMaNotMech < k; gssCMaNotMech++)
      pa[down[gssCMaNotMech].id] = gssCMaNotMech;

    memset(mark, 0, sizeof(mark));
    int ans = 0;
    for (gssCMaNotMech = 0; gssCMaNotMech < k; gssCMaNotMech++)
    {
      if (mark[gssCMaNotMech])
        continue;

      int now = pa[gssCMaNotMech];
      mark[gssCMaNotMech] = 1;
      int len = 1;
      while (now != gssCMaNotMech)
      {
        mark[now] = 1;
        len++;
        now = pa[now];
      }

      if (len > 1)
        ans += len;

    }

    printf("Case #%d: %d.000000\n", buttonPos, ans);
  }

  return 0;
}



void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}