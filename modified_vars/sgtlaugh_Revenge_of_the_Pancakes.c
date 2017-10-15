#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char string[12];
int n;
int lim;
int dis[1 << 12];
int temp2[1 << 12];
int bfs(int c)
{
  memset(dis, -1, sizeof(dis));
  int i;
  int time;
  int k;
  int c;
  int y;
  int mask;
  int front = 0;
  int len = 0;
  dis[c] = 0, temp2[len++] = c;
  while (front < len)
  {
    mask = temp2[front++];
    if (mask == lim)
      return dis[mask];

    for (i = 0; i < n; i++)
    {
      c = mask, y = mask;
      for (time = 0; time <= i; time++)
        c ^= 1 << time, y &= ~(1 << time);

      for (time = 0, k = i; time <= i; time++, k--)
      {
        if (c & (1 << time))
          y |= 1 << k;

      }

      if (dis[y] == (-1))
      {
        dis[y] = dis[mask] + 1;
        temp2[len++] = y;
      }

    }

  }

  return -1;
}

int Main()
{
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t = 0;
  int l;
  int i;
  int time;
  int k;
  int answer;
  int mask;
  scanf("%d", &l);
  while (l--)
  {
    scanf("%s", string);
    n = strlen(string), mask = 0, lim = (1 << n) - 1;
    for (i = 0; i < n; i++)
    {
      if (string[i] == '+')
        mask |= 1 << i;

    }

    printf("Case #%d: %d\n", ++t, bfs(mask));
  }

  return 0;
}


