#include <stdio.h>
int stack[1000003];
int heapn;
void heapinsert(int val)
{
  int first_iteration;
  int pos = heapn++;
  while ((pos > 1) && (val > stack[pos >> 1]))
  {
    stack[pos] = stack[pos >> 1];
    pos >>= 1;
  }

  stack[pos] = val;
}

void heapremove(int *val)
{
  int first_iteration;
  int pos = 1;
  int next = 1;
  int newval;
  *val = stack[1];
  newval = stack[--heapn];
  while ((pos << 1) <= heapn)
  {
    if ((pos << 1) == heapn)
      next = pos << 1;
    else
      next = (pos << 1) + (stack[pos << 1] < stack[(pos << 1) + 1]);

    if (stack[next] <= newval)
      break;

    stack[pos] = stack[next];
    pos = next;
  }

  stack[pos] = newval;
}

void clear()
{
  int first_iteration;
  int a;
  int s;
  int ti;
  int v1;
  int vy;
  scanf("%d %d", &a, &s);
  heapn = 1;
  heapinsert(a);
  while (s--)
  {
    heapremove(&ti);
    v1 = ti / 2;
    vy = (ti - 1) / 2;
    heapinsert(v1);
    heapinsert(vy);
    if (!s)
      printf("%d %d\n", v1, vy);

  }

}

int Main()
{
  int first_iteration;
  int tail;
  int caseno = 1;
  scanf("%d", &tail);
  while (tail--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}


