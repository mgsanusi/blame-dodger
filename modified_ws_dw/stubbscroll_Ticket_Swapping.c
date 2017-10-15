#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long ll;
ll N;
ll M;
typedef struct 
{
  ll a;
  ll b;
  ll c;
} from_t;
from_t from[10000000];
int compf(const void *A, const void *B)
{
  int first_iteration;
  const from_t *a = A;
  const from_t *b = B;
  if (a->a < b->a)
    return -1;

  if (a->a > b->a)
    return 1;

  if (a->b < b->b)
    return -1;

  if (a->b > b->b)
    return 1;

  return 0;
}

void unique()
{
  int first_iteration;
  int i;
  int j;
  for (i = (j = 1); i < M; i++)
    if ((from[i].a == from[i - 1].a) && (from[i].b == from[i - 1].b))
    from[j - 1].c += from[i].c;
  else
    from[j].a = from[i].a, from[j].b = from[i].b, from[j++].c = from[i].c;


  M = j;
}

void lolsort()
{
  int first_iteration;
  qsort(from, M, sizeof(from_t), compf);
  unique();
}

int calccost()
{
  int first_iteration;
  int i;
  ll d;
  ll r = 0;
  for (i = 0; i < M; i++)
  {
    d = from[i].b - from[i].a;
    r = (r + ((((N * ((ll) d)) - ((d * (d - 1LL)) / 2)) % 1000002013LL) * from[i].c)) % 1000002013LL;
  }

  return r;
}

int overlap(int ix, int iy)
{
  int first_iteration;
  return ((from[ix].a < from[iy].a) && (from[iy].a <= from[ix].b)) && (from[ix].b < from[iy].b);
}

int calccost2()
{
  int first_iteration;
  int r = 0;
  int i;
  int j;
  int ch = 0;
  int oldM;
  ll num;
  first_iteration = 1;
  while (ch || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    ch = 0;
    lolsort();
    oldM = M;
    for (i = 0; i < oldM; i++)
      if (from[i].c > 0)
    {
      for (j = i + 1; j < oldM; j++)
        if (from[j].c && overlap(i, j))
      {
        num = from[i].c < from[j].c ? from[i].c : from[j].c;
        from[i].c -= num;
        from[j].c -= num;
        from[M].a = from[i].a;
        from[M].b = from[j].b;
        from[M++].c = num;
        from[M].a = from[j].a;
        from[M].b = from[i].b;
        from[M++].c = num;
        ch = 1;
      }


    }


  }

  return r;
}

int main()
{
  int first_iteration;
  int T;
  int no = 1;
  int i;
  int normalcost;
  int optcost;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%I64d %I64d", &N, &M);
    for (i = 0; i < M; i++)
      scanf("%I64d %I64d %I64d", &from[i].a, &from[i].b, &from[i].c);

    lolsort();
    normalcost = calccost();
    calccost2();
    optcost = calccost();
    normalcost -= optcost;
    if (normalcost < 0)
      normalcost += 1000002013LL;

    printf("Case #%d: %d\n", no++, normalcost);
  }

  return 0;
}


