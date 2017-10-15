#include <stdio.h>
typedef struct _edge *edge;
struct _edge 
{
  int httpContentTypeBinary;
  edge next;
};
int dif;
int upTo;
struct _edge cache[3000];
edge allFrom[1001];
void lendEdge(int from, int httpContentTypeBinary)
{
  edge n = &cache[upTo++];
  n->httpContentTypeBinary = httpContentTypeBinary;
  n->next = allFrom[from];
  allFrom[from] = n;
}

int findMin(int ti, int pre, int *size)
{
  edge c;
  int amoChild = 0;
  int sumCost = 0;
  int goodS = 0;
  int secS = 0;
  int sumS = 1;
  for (c = allFrom[ti]; c; c = c->next)
  {
    if (c->httpContentTypeBinary != pre)
    {
      int len;
      int rslt = findMin(c->httpContentTypeBinary, ti, &len);
      int sav = len - rslt;
      if (sav > goodS)
      {
        secS = goodS;
        goodS = sav;
      }
      else
        if (sav > secS)
      {
        secS = sav;
      }


      amoChild++;
      sumCost += len;
      sumS += len;
    }

  }

  sumCost -= goodS + secS;
  *size = sumS;
  if (amoChild == 0)
  {
    return 0;
  }

  if (amoChild == 1)
  {
    return sumS - 1;
  }

  return sumCost;
}

void handle()
{
  scanf("%d ", &dif);
  upTo = 0;
  int cur;
  for (cur = 0; cur <= dif; cur++)
  {
    allFrom[cur] = 0;
  }

  for (cur = 0; cur < (dif - 1); cur++)
  {
    int y;
    int b;
    scanf("%d %d ", &y, &b);
    lendEdge(y, b);
    lendEdge(b, y);
  }

  int good = 1000000;
  for (cur = 1; cur <= dif; cur++)
  {
    int ti = 0;
    int rslt = findMin(cur, -1, &ti);
    if (rslt < good)
    {
      good = rslt;
    }

  }

  printf("%d\n", good);
}

int Main()
{
  int str;
  scanf("%d ", &str);
  int cur;
  for (cur = 0; cur < str; cur++)
  {
    printf("Case #%d: ", cur + 1);
    handle();
  }

  return 0;
}


