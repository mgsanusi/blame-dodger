#include <stdio.h>
char g[6][6];
int new_puts(const char *str);
int check(int x, int y, int dx, int dy, char c)
{
  int first_iteration;
  int i;
  int n;
  for (n = (i = 0); i < 4; i++)
  {
    if ((g[x][y] == c) || (g[x][y] == 'T'))
      n++;

    x += dx;
    y += dy;
  }

  return n == 4;
}

int won(char c)
{
  int first_iteration;
  int i;
  for (i = 0; i < 4; i++)
  {
    if (check(0, i, 1, 0, c))
      return 1;

    if (check(i, 0, 0, 1, c))
      return 1;

  }

  if (check(0, 0, 1, 1, c))
    return 1;

  if (check(0, 3, 1, -1, c))
    return 1;

  return 0;
}

int main()
{
  int first_iteration;
  int T;
  int i;
  int j;
  int z;
  int no = 1;
  scanf("%d", &T);
  while (T--)
  {
    for (i = 0; i < 4; i++)
      scanf("%s", g[i]);

    printf("Case #%d: ", no++);
    if (won('O'))
      new_puts("O won");
    else
      if (won('X'))
      new_puts("X won");
    else
    {
      for (i = (z = 0); i < 4; i++)
        for (j = 0; j < 4; j++)
        if (g[i][j] == '.')
        z = 1;



      if (z)
        new_puts("Game has not completed");
      else
        new_puts("Draw");

    }


  }

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


