#include<stdio.h>
struct A
{
  int x2;
  int l;
  int d;
} walk[1000];
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int cmp(const void *a, const void *x2)
{
  return ((struct A *) a)->d - ((struct A *) x2)->d;
}

int Main()
{
  int t;
  int type_sort;
  scanf("%d", &t);
  for (type_sort = 1; type_sort <= t; type_sort++)
  {
    int x;
    int m;
    int cl_destroy;
    int h;
    int dy;
    double t;
    memset(walk, 0, sizeof(walk));
    scanf("%d%d%d%d%d", &x, &m, &cl_destroy, &h, &dy);
    t = h;
    int heapn;
    double plain = x;
    for (heapn = 0; heapn < dy; heapn++)
    {
      scanf("%d%d%d", &walk[heapn].x2, &walk[heapn].l, &walk[heapn].d);
      plain -= walk[heapn].l - walk[heapn].x2;
    }

    new_qsort(walk, dy, sizeof(struct A), cmp);
    double result = 0;
    double time = plain / ((double) cl_destroy);
    if (time > t)
    {
      time = t + ((plain - (cl_destroy * t)) / ((double) m));
      t = 0;
    }
    else
    {
      t -= time;
    }

    result += time;
    for (heapn = 0; heapn < dy; heapn++)
    {
      double time = ((double) (walk[heapn].l - walk[heapn].x2)) / ((double) (cl_destroy + walk[heapn].d));
      if (time > t)
      {
        time = t + ((((double) (walk[heapn].l - walk[heapn].x2)) - ((cl_destroy + walk[heapn].d) * t)) / ((double) (m + walk[heapn].d)));
        t = 0;
      }
      else
        t -= time;

      result += time;
    }

    printf("Case #%d: %.8lf\n", type_sort, result);
  }

  return 0;
}



void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}