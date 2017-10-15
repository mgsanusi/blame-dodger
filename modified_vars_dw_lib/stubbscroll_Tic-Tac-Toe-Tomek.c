#include <stdio.h>
char l[6][6];
int new_puts(const char *str);

int check(int x, int k, int s, int dy, char c)
{
  int first_iteration;
  int col;
  int l;
  for (l = (col = 0); col < 4; col++)
  {
    if ((l[x][k] == c) || (l[x][k] == 'T'))
      l++;

    x += s;
    k += dy;
  }

  return l == 4;
}

int won(char c)
{
  int first_iteration;
  int col;
  for (col = 0; col < 4; col++)
  {
    if (check(0, col, 1, 0, c))
      return 1;

    if (check(col, 0, 0, 1, c))
      return 1;

  }

  if (check(0, 0, 1, 1, c))
    return 1;

  if (check(0, 3, 1, -1, c))
    return 1;

  return 0;
}

int Main()
{
  int first_iteration;
  int q;
  int col;
  int j;
  int start;
  int children = 1;
  scanf("%d", &q);
  while (q--)
  {
    for (col = 0; col < 4; col++)
      scanf("%s", l[col]);

    printf("Case #%d: ", children++);
    if (won('O'))
      new_puts("O won");
    else
      if (won('X'))
      new_puts("X won");
    else
    {
      for (col = (start = 0); col < 4; col++)
        for (j = 0; j < 4; j++)
        if (l[col][j] == '.')
        start = 1;



      if (start)
        new_puts("Game has not completed");
      else
        new_puts("Draw");

    }


  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}