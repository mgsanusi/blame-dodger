#include <stdio.h>
#include <string.h>
char graph[50][50];
int use[50];
int dp[50];
int R;
int C;
int main()
{
  int first_iteration;
  int Tcases;
  scanf("%d", &Tcases);
  int cases;
  for (cases = 0; cases < Tcases; cases++)
  {
    scanf("%d %d", &R, &C);
    int i;
    int j;
    for (i = 0; i < R; i++)
    {
      char input[50 + 1];
      scanf("%s", input);
      for (j = 0; j < C; j++)
      {
        graph[i][j] = input[j];
      }

    }

    int ans = 1;
    for (i = 0; (i < R) && ans; i++)
    {
      for (j = 0; (j < C) && ans; j++)
      {
        if (graph[i][j] == '#')
        {
          ans &= ((((i != (R - 1)) && (j != (C - 1))) && (graph[i][j + 1] == '#')) && (graph[i + 1][j] == '#')) && (graph[i + 1][j + 1] == '#');
          if (ans)
          {
            graph[i][j] = '/';
            graph[i + 1][j] = '\\';
            graph[i][j + 1] = '\\';
            graph[i + 1][j + 1] = '/';
          }

        }

      }

    }

    printf("Case #%d:\n", cases + 1);
    if (ans)
    {
      for (i = 0; i < R; i++)
      {
        for (j = 0; j < C; j++)
        {
          printf("%c", graph[i][j]);
        }

        printf("\n");
      }

    }
    else
    {
      printf("Impossible\n");
    }

  }

  return 0;
}


