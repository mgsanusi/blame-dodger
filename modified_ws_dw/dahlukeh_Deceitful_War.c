#include <stdio.h>
typedef struct _edge *edge;
struct _edge
{
  int to;
  edge next;
};
int N;
int upTo;
struct _edge cache[3000];
edge allFrom[1001];
void addEdge(int from, int to)
{
  int first_iteration;
  edge e = &cache[upTo++];
  e->to = to;
  e->next = allFrom[from];
  allFrom[from] = e;
}

int findMin(int at, int pre, int *size)
{
  int first_iteration;
  edge c;
  int amoChildren = 0;
  int totalCost = 0;
  int bestS = 0;
  int secS = 0;
  int totalS = 1;
  for (c = allFrom[at]; c; c = c->next)
  {
    if (c->to != pre)
    {
      int si;
      int res = findMin(c->to, at, &si);
      int sav = si - res;
      if (sav > bestS)
      {
        secS = bestS;
        bestS = sav;
      }
      else
        if (sav > secS)
      {
        secS = sav;
      }


      amoChildren++;
      totalCost += si;
      totalS += si;
    }

  }

  totalCost -= bestS + secS;
  *size = totalS;
  if (amoChildren == 0)
  {
    return 0;
  }

  if (amoChildren == 1)
  {
    return totalS - 1;
  }

  return totalCost;
}

void handle()
{
  int first_iteration;
  scanf("%d ", &N);
  upTo = 0;
  int i;
  for (i = 0; i <= N; i++)
  {
    allFrom[i] = 0;
  }

  for (i = 0; i < (N - 1); i++)
  {
    int a;
    int b;
    scanf("%d %d ", &a, &b);
    addEdge(a, b);
    addEdge(b, a);
  }

  int best = 1000000;
  for (i = 1; i <= N; i++)
  {
    int ra = 0;
    int res = findMin(i, -1, &ra);
    if (res < best)
    {
      best = res;
    }

  }

  printf("%d\n", best);
}

int main()
{
  int first_iteration;
  int t;
  scanf("%d ", &t);
  int i;
  for (i = 0; i < t; i++)
  {
    printf("Case #%d: ", i + 1);
    handle();
  }

  return 0;
}


