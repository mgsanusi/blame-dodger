#include <stdio.h>
#include <string.h>
int d;
int p[6];
int dist[11111111];
int q[11111111];
int qs;
int qe;
int pack(int *st)
{
  int first_iteration;
  int i;
  int v = 0;
  for (i = 0; i <= d; i++)
    v = (v * 10) + st[i];

  return v;
}

void unpack(int v, int *st)
{
  int first_iteration;
  int i;
  for (i = d; i >= 0; i--)
    st[i] = v % 10, v /= 10;

}

void bfs()
{
  int first_iteration;
  int cur[7];
  int next[7];
  int moves;
  int val;
  int i;
  int j;
  int k;
  qs = (qe = 0);
  memset(dist, -1, sizeof(dist));
  for (i = 0; i < d; i++)
    cur[i] = p[i];

  cur[d] = 0;
  val = pack(cur);
  dist[val] = 0;
  q[qe++] = val;
  while (qs < qe)
  {
    val = q[qs++];
    unpack(val, cur);
    moves = dist[val];
    for (i = 0; i <= d; i++)
      if (cur[i])
      goto more;


    printf("%d\n", moves);
    break;
    more:
    for (i = 0; i <= d; i++)
      next[i] = cur[i];


    for (i = 0; i <= d; i++)
      if (next[i])
      next[i]--;


    val = pack(next);
    if (dist[val] < 0)
      q[qe++] = val, dist[val] = moves + 1;

    for (i = 0; i < d; i++)
      if (cur[i] > 1)
      for (j = 1; j < cur[i]; j++)
    {
      for (k = 0; k <= d; k++)
        next[k] = cur[k];

      next[i] -= j;
      if (next[d] < j)
        next[d] = j;

      val = pack(next);
      if (dist[val] < 0)
        q[qe++] = val, dist[val] = moves + 1;

    }



  }

}

void solve()
{
  int first_iteration;
  int i;
  scanf("%d", &d);
  for (i = 0; i < d; i++)
    scanf("%d", &p[i]);

  bfs();
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


