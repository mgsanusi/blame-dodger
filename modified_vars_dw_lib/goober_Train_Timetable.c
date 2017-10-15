#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  int l;
  int d;
} REC;
REC la[200];
REC lb[200];
void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int cmp(const void *aa, const void *f)
{
  int first_iteration;
  const REC *p = (const REC *) aa;
  const REC *str = (const REC *) f;
  if (p->l != str->l)
    return p->l - str->l;

  return str->d - p->d;
}

int Main()
{
  int first_iteration;
  int k;
  scanf("%d", &k);
  for (int c = 1; c <= k; c++)
  {
    int l;
    int cont;
    int nb;
    scanf("%d", &l);
    scanf("%d %d", &cont, &nb);
    for (int min = 0; min < cont; min++)
    {
      int gid;
      int k;
      int res;
      int len;
      scanf("%d:%d %d:%d", &gid, &k, &res, &len);
      la[min].l = (60 * gid) + k;
      la[min].d = -1;
      lb[min].l = ((60 * res) + len) + l;
      lb[min].d = +1;
    }

    for (int min = cont; min < (cont + nb); min++)
    {
      int gid;
      int k;
      int res;
      int len;
      scanf("%d:%d %d:%d", &gid, &k, &res, &len);
      lb[min].l = (60 * gid) + k;
      lb[min].d = -1;
      la[min].l = ((60 * res) + len) + l;
      la[min].d = +1;
    }

    new_qsort(la, cont + nb, sizeof(REC), cmp);
    new_qsort(lb, cont + nb, sizeof(REC), cmp);
    int cs = 0;
    int j = 0;
    for (int min = 0; min < (cont + nb); min++)
    {
      j += la[min].d;
      if (j < cs)
        cs = j;

    }

    int numStart = 0;
    int rpi = 0;
    for (int min = 0; min < (cont + nb); min++)
    {
      rpi += lb[min].d;
      if (rpi < numStart)
        numStart = rpi;

    }

    printf("Case #%d: %d %d\n", c, -cs, -numStart);
  }

  return 0;
}



void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}