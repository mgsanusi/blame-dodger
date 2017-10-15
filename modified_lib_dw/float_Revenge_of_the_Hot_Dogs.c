#include <stdio.h>
#include <stdlib.h>
char map[100][100];
int R;
int C;
int new_puts(const char *str);
int rep()
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < R; i++)
  {
    for (j = 0; j < C; j++)
    {
      if ((((map[i][j] == '#') && (map[i + 1][j] == '#')) && (map[i][j + 1] == '#')) && (map[i + 1][j + 1] == '#'))
      {
        map[i][j] = '/';
        map[i + 1][j] = '\\';
        map[i][j + 1] = '\\';
        map[i + 1][j + 1] = '/';
      }

    }

  }

}

int check()
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < R; i++)
    for (j = 0; j < C; j++)
    if (map[i][j] == '#')
    return 0;



  return 1;
}

int main()
{
  int first_iteration;
  int cas;
  int c;
  int i;
  scanf("%d", &cas);
  for (c = 1; c <= cas; c++)
  {
    scanf("%d %d", &R, &C);
    for (i = 0; i < R; i++)
      scanf("%s", map[i]);

    rep();
    printf("Case #%d:\n", c);
    if (check())
    {
      for (i = 0; i < R; i++)
        new_puts(map[i]);

    }
    else
      new_puts("Impossible");

  }

}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


