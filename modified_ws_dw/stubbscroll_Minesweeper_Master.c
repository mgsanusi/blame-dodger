#include <stdio.h>
#include <string.h>
int x;
int y;
int m;
char g[10][10];
int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};
int snoob(int x)
{
  int first_iteration;
  int s = x & (-x);
  int r = x + s;
  int o = x ^ r;
  o = (o >> 2) / s;
  return r | o;
}

int can(int cx, int cy)
{
  int first_iteration;
  int tall[10][10];
  char vis[10][10];
  int i;
  int j;
  int x2;
  int y2;
  int ax;
  int ay;
  int k;
  int q[155];
  int qs;
  int qe;
  for (i = 0; i < x; i++)
    for (j = 0; j < y; j++)
  {
    tall[i][j] = 0;
    for (k = 0; k < 8; k++)
    {
      x2 = i + dx[k];
      y2 = j + dy[k];
      if (((((x2 >= 0) && (y2 >= 0)) && (x2 < x)) && (y2 < y)) && (g[x2][y2] == '*'))
        tall[i][j]++;

    }

  }


  memset(vis, 0, sizeof(vis));
  qs = (qe = 0);
  q[qe++] = cx;
  q[qe++] = cy;
  vis[cx][cy] = 1;
  while (qs < qe)
  {
    ax = q[qs++];
    ay = q[qs++];
    if (!tall[ax][ay])
    {
      for (k = 0; k < 8; k++)
      {
        x2 = ax + dx[k];
        y2 = ay + dy[k];
        if ((((x2 < 0) || (y2 < 0)) || (x2 >= x)) || (y2 >= y))
          continue;

        if (vis[x2][y2])
          continue;

        q[qe++] = x2;
        q[qe++] = y2;
        vis[x2][y2] = 1;
      }

    }

  }

  for (i = 0; i < x; i++)
    for (j = 0; j < y; j++)
    if ((g[i][j] == '.') && (!vis[i][j]))
    return 0;



  g[cx][cy] = 'c';
  for (i = 0; i < x; i++)
    puts(g[i]);

  return 1;
}

void solve()
{
  int first_iteration;
  int i;
  int j;
  int mask;
  int k;
  scanf("%d %d %d", &x, &y, &m);
  mask = (1 << m) - 1;
  memset(g, 0, sizeof(g));
  first_iteration = 1;
  while ((mask < (1 << (x * y))) || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    for (k = (i = 0); i < x; i++)
      for (j = 0; j < y; j++, k++)
      g[i][j] = mask & (1 << k) ? '*' : '.';


    for (i = 0; i < x; i++)
      for (j = 0; j < y; j++)
      if ((g[i][j] == '.') && can(i, j))
      return;



    mask = snoob(mask);
  }

  puts("Impossible");
}

int main()
{
  int first_iteration;
  int T;
  int no = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d:\n", no++), solve();

  return 0;
}


