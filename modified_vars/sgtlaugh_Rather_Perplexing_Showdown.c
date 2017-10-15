#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char str[30];
int visit[16][16];
int dp[16][16];
int t;
int n;
int id = 0;
int lim = 0;
int ar[4][4];
int cur[4][4];
int r(int i, int a, int s2)
{
  if (i == n)
    return 1;

  if (visit[a][s2] == id)
    return dp[a][s2];

  int j;
  int _p;
  int x;
  int ans = 1;
  int counter = 0;
  for (j = 0; (j < n) && (ans == 1); j++)
  {
    if (!(a & (1 << j)))
    {
      for (_p = 0; _p < n; _p++)
      {
        if (cur[j][_p] && (!(s2 & (1 << _p))))
        {
          if (!r(i + 1, a | (1 << j), s2 | (1 << _p)))
          {
            ans = 0;
            break;
          }

          counter++;
        }

      }

    }

  }

  if (!counter)
    ans = 0;

  visit[a][s2] = id;
  return dp[a][s2] = ans;
}

int Main()
{
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t = 0;
  int i;
  int j;
  int _p;
  int c;
  int x;
  int y;
  int ans;
  int mask;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%s", str);
      for (j = 0; j < n; j++)
      {
        ar[i][j] = str[j] - 48;
      }

    }

    ans = 1010, lim = (1 << (n * n)) - 1;
    for (c = 0; (c <= (n * n)) && (ans == 1010); c++)
    {
      for (mask = 0; mask <= lim; mask++)
      {
        if (__builtin_popcount(mask) == c)
        {
          for (i = 0, _p = 0; i < n; i++)
          {
            for (j = 0; j < n; j++, _p++)
            {
              cur[i][j] = ar[i][j];
              if (mask & (1 << _p))
                cur[i][j] = 1;

            }

          }

          id++;
          if (r(0, 0, 0))
          {
            ans = c;
            break;
          }

        }

      }

    }

    printf("Case #%d: %d\n", ++t, ans);
  }

  return 0;
}


