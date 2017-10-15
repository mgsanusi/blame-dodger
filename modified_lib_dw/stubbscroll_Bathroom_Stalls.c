#include <stdio.h>
int heap[1000003];
int heapn;
void heapinsert(int val)
{
  int first_iteration;
  int pos = heapn++;
  while ((pos > 1) && (val > heap[pos >> 1]))
  {
    heap[pos] = heap[pos >> 1];
    pos >>= 1;
  }

  heap[pos] = val;
}

void heapremove(int *val)
{
  int first_iteration;
  int pos = 1;
  int next = 1;
  int newval;
  *val = heap[1];
  newval = heap[--heapn];
  while ((pos << 1) <= heapn)
  {
    if ((pos << 1) == heapn)
      next = pos << 1;
    else
      next = (pos << 1) + (heap[pos << 1] < heap[(pos << 1) + 1]);

    if (heap[next] <= newval)
      break;

    heap[pos] = heap[next];
    pos = next;
  }

  heap[pos] = newval;
}

void solve()
{
  int first_iteration;
  int n;
  int k;
  int v;
  int v1;
  int v2;
  scanf("%d %d", &n, &k);
  heapn = 1;
  heapinsert(n);
  while (k--)
  {
    heapremove(&v);
    v1 = v / 2;
    v2 = (v - 1) / 2;
    heapinsert(v1);
    heapinsert(v2);
    if (!k)
      printf("%d %d\n", v1, v2);

  }

}

int main()
{
  int first_iteration;
  int T;
  int caseno = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", caseno++), solve();

  return 0;
}


