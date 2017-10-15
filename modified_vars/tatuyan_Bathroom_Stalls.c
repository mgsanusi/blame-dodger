#include<stdio.h>
#include<stdlib.h>
struct sec
{
  int s;
  int k;
  int size;
};
void clear(int casenum);
void totalBatch(struct sec *arr, int n, struct sec new);
struct sec startHeaproot(struct sec *arr, int n);
int comp(struct sec a, struct sec prev);
int Main(void)
{
  int buf;
  int id;
  scanf("%d", &buf);
  for (id = 1; id <= buf; id++)
    clear(id);

  return 0;
}

void clear(int casenum)
{
  struct sec *q;
  struct sec get;
  struct sec d[2];
  struct sec *freep;
  int qn;
  int id;
  int dd;
  int n;
  int sinrad;
  int ls;
  int rs;
  scanf("%d%d", &n, &sinrad);
  if (n == sinrad)
  {
    printf("Case #%d: %d %d\n", casenum, 0, 0);
    return;
  }

  freep = (q = (struct sec *) calloc(1000000, sizeof(struct sec)));
  for (id = 1; id <= n; id++)
    q[id] = (struct sec) {0, 0, 0};

  q[0] = (struct sec) {1, n, (n - 1) + 1};
  qn = 1;
  for (id = 0; id < sinrad; id++)
  {
    get = startHeaproot(q, qn--);
    d[0] = (struct sec) {get.s, ((get.s + get.k) / 2) - 1, ((get.s + get.k) / 2) - get.s};
    d[1] = (struct sec){((get.s + get.k) / 2) + 1, get.k, get.k - ((get.s + get.k) / 2)};
    if (((d[0].s > 0) && (d[0].k >= d[0].s)) && (d[0].size > 0))
      totalBatch(q, qn++, d[0]);

    if (((d[1].s > 0) && (d[1].k >= d[1].s)) && (d[1].size > 0))
      totalBatch(q, qn++, d[1]);

  }

  ls = ((get.s + get.k) / 2) - get.s;
  rs = get.k - ((get.s + get.k) / 2);
  printf("Case #%d: %d %d\n", casenum, ls < rs ? rs : ls, ls > rs ? rs : ls);
  free(freep);
}

int comp(struct sec a, struct sec prev)
{
  if (a.size > prev.size)
    return 1;

  if (a.size < prev.size)
    return -1;

  if (a.s < prev.s)
    return 1;

  return -1;
}

void totalBatch(struct sec *arr, int n, struct sec new)
{
  struct sec swaps;
  int id;
  int next;
  int tmp;
  arr[n] = new;
  for (id = n; id > 0; id = (id - 1) / 2)
  {
    if (comp(arr[(id - 1) / 2], arr[id]) == (-1))
    {
      swaps = arr[id];
      arr[id] = arr[(id - 1) / 2];
      arr[(id - 1) / 2] = swaps;
    }
    else
      break;

  }

}

struct sec startHeaproot(struct sec *arr, int n)
{
  struct sec ret;
  struct sec swaps;
  int id;
  int next;
  int tmp;
  ret = arr[0];
  arr[0] = arr[n - 1];
  for (id = 0; (2 * id) < (n - 2); id = next)
  {
    if ((((2 * id) + 2) < (n - 1)) && (comp(arr[(2 * id) + 2], arr[(2 * id) + 1]) == 1))
      next = (2 * id) + 2;
    else
      next = (2 * id) + 1;

    if (comp(arr[next], arr[id]) == 1)
    {
      swaps = arr[id];
      arr[id] = arr[next];
      arr[next] = swaps;
    }
    else
      break;

  }

  return ret;
}


