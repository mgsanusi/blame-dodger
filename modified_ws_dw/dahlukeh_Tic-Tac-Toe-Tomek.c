#include <stdio.h>
#include <stdlib.h>
void handleCase();
int getResult(int x, int y, int t);
int grid[4][4];
int dx[] = {0, 1, 1, -1};
int dy[] = {1, 1, 0, 1};
int main()
{
  int first_iteration;
  freopen("ain.txt", "r", stdin);
  freopen("aout.txt", "w", stdout);
  int n;
  scanf("%d ", &n);
  int i;
  for (i = 0; i < n; i++)
  {
    printf("Case #%d: ", i + 1);
    handleCase();
  }

  return 0;
}

void handleCase()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int full = 1;
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      char c;
      int type;
      scanf("%c ", &c);
      if (c == 'X')
      {
        type = 0;
      }
      else
        if (c == 'O')
      {
        type = 1;
      }
      else
        if (c == 'T')
      {
        type = 2;
      }
      else
      {
        full = 0;
        type = 3;
      }



      grid[i][j] = type;
    }

  }

  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      for (k = 0; k < 4; k++)
      {
        int result = getResult(j, i, k);
        if (result == 0)
        {
          printf("X won\n");
          return;
        }
        else
          if (result == 1)
        {
          printf("O won\n");
          return;
        }


      }

    }

  }

  if (full)
  {
    printf("Draw\n");
  }
  else
  {
    printf("Game has not completed\n");
  }

}

int getResult(int x, int y, int t)
{
  int first_iteration;
  int i;
  int cur = 2;
  for (i = 0; i < 4; i++)
  {
    if ((((x >= 4) || (y >= 4)) || (x < 0)) || (y < 0))
    {
      return 2;
    }

    if (grid[y][x] == 3)
    {
      return 2;
    }

    if (grid[y][x] != 2)
    {
      if ((cur == 2) || (cur == grid[y][x]))
      {
        cur = grid[y][x];
      }
      else
      {
        return 2;
      }

    }

    x += dx[t];
    y += dy[t];
  }

  return cur;
}


