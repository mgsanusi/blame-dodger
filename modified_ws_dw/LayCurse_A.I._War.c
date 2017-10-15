#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
int edge[510][510];
int es[510];
int edge_mat[510][510];
int dist[500];
int q[500];
int q_st;
int q_size;
int now[510];
int chk[510];
int best;
void solve(int node)
{
  int first_iteration;
  int i;
  int j;
  int k;
  now[dist[node]] = node;
  if (node == 1)
  {
    for (i = 0; i < n; i++)
      chk[i] = 0;

    for (i = 0; i < dist[node]; i++)
      for (j = 0; j < es[now[i]]; j++)
      chk[edge[now[i]][j]] = 1;


    k = 0;
    for (i = 0; i < n; i++)
      k += chk[i];

    k -= dist[node] - 1;
    if (dist[node] > 1)
      k--;

    if (best < k)
      best = k;

    return;
  }

  for (i = 0; i < es[node]; i++)
  {
    k = edge[node][i];
    if ((dist[node] + 1) != dist[k])
      continue;

    solve(k);
  }

}

int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
      es[i] = 0;

    while (m--)
    {
      scanf(" %d,%d ", &i, &j);
      edge[i][es[i]++] = j;
      edge[j][es[j]++] = i;
    }

    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
      edge_mat[i][j] = 0;


    for (i = 0; i < n; i++)
      for (j = 0; j < es[i]; j++)
      edge_mat[i][edge[i][j]] = 1;


    for (i = 0; i < n; i++)
      dist[i] = -1;

    dist[0] = 0;
    q_size = 1;
    q_st = 0;
    q[0] = 0;
    while (q_size)
    {
      i = q[q_st++];
      q_size--;
      for (j = 0; j < es[i]; j++)
      {
        k = edge[i][j];
        if (dist[k] >= 0)
          continue;

        dist[k] = dist[i] + 1;
        q[q_st + (q_size++)] = k;
      }

    }

    best = 0;
    solve(0);
    k = best;
    printf("Case #%d: %d %d\n", ++count, dist[1] - 1, k);
  }

  return 0;
}


