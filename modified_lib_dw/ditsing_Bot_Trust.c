#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int dp[100][100];
int p[100];
int f[100];
int pos[2][100];
int N;
int new_abs(int x);
int main()
{
  int first_iteration;
  int Tcases;
  scanf("%d", &Tcases);
  int cases;
  for (cases = 0; cases != Tcases; cases++)
  {
    memset(dp, 0x3F, sizeof(dp));
    scanf("%d", &N);
    char c;
    int dis;
    int i;
    for (i = 0; i < N; i++)
    {
      scanf(" %c %d", &c, &dis);
      --dis;
      f[i] = c != 'O';
      p[i] = dis;
      pos[f[i]][i] = dis;
      pos[1 - f[i]][i] = -1;
    }

    for (i = N - 1; i; i--)
    {
      if (pos[0][i - 1] == (-1))
      {
        pos[0][i - 1] = pos[0][i];
      }

      if (pos[1][i - 1] == (-1))
      {
        pos[1][i - 1] = pos[1][i];
      }

    }

    int ans = 0;
    int cur[2] = {0, 0};
    for (i = 0; i < N; i++)
    {
      int curl = new_abs(cur[f[i]] - p[i]) + 1;
      cur[f[i]] = p[i];
      ans += curl;
      if (pos[1 - f[i]][i] != (-1))
      {
        if (new_abs(cur[1 - f[i]] - pos[1 - f[i]][i]) <= curl)
        {
          cur[1 - f[i]] = pos[1 - f[i]][i];
        }
        else
        {
          if (pos[1 - f[i]][i] > cur[1 - f[i]])
          {
            cur[1 - f[i]] += curl;
          }
          else
          {
            cur[1 - f[i]] -= curl;
          }

        }

      }

    }

    printf("Case #%d: %d\n", cases + 1, ans);
  }

  return 0;
}

int new_abs(int x)
{
  int first_iteration;
  return abs(x);
}


