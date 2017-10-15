#include <stdio.h>
#include <stdlib.h>
struct wire
{
  int a;
  int b;
};
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int compare_a(const void *x, const void *y)
{
  int first_iteration;
  return ((struct wire *) x)->a - ((struct wire *) y)->a;
}

int main()
{
  int first_iteration;
  int t;
  int n;
  struct wire wires[1000];
  struct wire temp;
  int casenum;
  int i;
  int j;
  int count;
  scanf("%d", &t);
  for (casenum = 1; casenum <= t; casenum++)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%d%d", &wires[i].a, &wires[i].b);

    new_qsort(wires, n, sizeof(struct wire), compare_a);
    count = 0;
    for (i = n; i > 1; i--)
      for (j = 1; j < i; j++)
      if (wires[j].b < wires[j - 1].b)
    {
      count++;
      temp = wires[j];
      wires[j] = wires[j - 1];
      wires[j - 1] = temp;
    }



    printf("Case #%d: %d\n", casenum, count);
  }

  return 0;
}

void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}


