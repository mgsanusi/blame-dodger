#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int r;
int edge[510][510];
int cmx[510];
int edgeMat[510][510];
int dist[500];
int q[500];
int qSt;
int qSize;
int now[510];
int chk[510];
int good;
void clear(int node)
{
  int g;
  int pos;
  int p;
  now[dist[node]] = node;
  if (node == 1)
  {
    for (g = 0; g < r; g++)
      chk[g] = 0;

    for (g = 0; g < dist[node]; g++)
      for (pos = 0; pos < cmx[now[g]]; pos++)
      chk[edge[now[g]][pos]] = 1;


    p = 0;
    for (g = 0; g < r; g++)
      p += chk[g];

    p -= dist[node] - 1;
    if (dist[node] > 1)
      p--;

    if (good < p)
      good = p;

    return;
  }

  for (g = 0; g < cmx[node]; g++)
  {
    p = edge[node][g];
    if ((dist[node] + 1) != dist[p])
      continue;

    clear(p);
  }

}

int Main()
{
  int g;
  int pos;
  int p;
  int l;
  int m;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &r, &m);
    for (g = 0; g < r; g++)
      cmx[g] = 0;

    while (m--)
    {
      scanf(" %d,%d ", &g, &pos);
      edge[g][cmx[g]++] = pos;
      edge[pos][cmx[pos]++] = g;
    }

    for (g = 0; g < r; g++)
      for (pos = 0; pos < r; pos++)
      edgeMat[g][pos] = 0;


    for (g = 0; g < r; g++)
      for (pos = 0; pos < cmx[g]; pos++)
      edgeMat[g][edge[g][pos]] = 1;


    for (g = 0; g < r; g++)
      dist[g] = -1;

    dist[0] = 0;
    qSize = 1;
    qSt = 0;
    q[0] = 0;
    while (qSize)
    {
      g = q[qSt++];
      qSize--;
      for (pos = 0; pos < cmx[g]; pos++)
      {
        p = edge[g][pos];
        if (dist[p] >= 0)
          continue;

        dist[p] = dist[g] + 1;
        q[qSt + (qSize++)] = p;
      }

    }

    good = 0;
    clear(0);
    p = good;
    printf("Case #%d: %d %d\n", ++count, dist[1] - 1, p);
  }

  return 0;
}


