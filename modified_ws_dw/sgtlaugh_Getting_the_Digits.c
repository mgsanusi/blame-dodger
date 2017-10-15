#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool visited[1 << 17];
int t;
int n;
int lim;
int dp[1 << 17];
char first[1010][25];
char second[1010][25];
int F(int mask)
{
  int first_iteration;
  if (mask == lim)
    return 0;

  if (visited[mask])
    return dp[mask];

  int i;
  int j;
  int x;
  int y;
  int z;
  int res = 0;
  for (i = 0; i < n; i++)
  {
    if (!(mask & (1 << i)))
    {
      x = 0, y = 0;
      for (j = 0; j < n; j++)
      {
        if (mask & (1 << j))
        {
          if (strcmp(first[i], first[j]) == 0)
            x++;

          if (strcmp(second[i], second[j]) == 0)
            y++;

        }

      }

      z = F(mask | (1 << i)) + ((x > 0) && (y > 0));
      if (z > res)
        res = z;

    }

  }

  visited[mask] = 1;
  return dp[mask] = res;
}

int main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T = 0;
  int i;
  int j;
  int k;
  int x;
  int res;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%s %s", first[i], second[i]);

    memset(visited, 0, sizeof(visited));
    lim = (1 << n) - 1;
    printf("Case #%d: %d\n", ++T, F(0));
  }

  return 0;
}


