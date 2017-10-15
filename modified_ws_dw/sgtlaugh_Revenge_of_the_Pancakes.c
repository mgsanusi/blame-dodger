#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char str[12];
int n;
int lim;
int dis[1 << 12];
int Q[1 << 12];
int bfs(int s)
{
  int first_iteration;
  memset(dis, -1, sizeof(dis));
  int i;
  int j;
  int k;
  int x;
  int y;
  int mask;
  int front = 0;
  int len = 0;
  dis[s] = 0, Q[len++] = s;
  while (front < len)
  {
    mask = Q[front++];
    if (mask == lim)
      return dis[mask];

    for (i = 0; i < n; i++)
    {
      x = mask, y = mask;
      for (j = 0; j <= i; j++)
        x ^= 1 << j, y &= ~(1 << j);

      for (j = 0, k = i; j <= i; j++, k--)
      {
        if (x & (1 << j))
          y |= 1 << k;

      }

      if (dis[y] == (-1))
      {
        dis[y] = dis[mask] + 1;
        Q[len++] = y;
      }

    }

  }

  return -1;
}

int main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T = 0;
  int t;
  int i;
  int j;
  int k;
  int res;
  int mask;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%s", str);
    n = strlen(str), mask = 0, lim = (1 << n) - 1;
    for (i = 0; i < n; i++)
    {
      if (str[i] == '+')
        mask |= 1 << i;

    }

    printf("Case #%d: %d\n", ++T, bfs(mask));
  }

  return 0;
}


