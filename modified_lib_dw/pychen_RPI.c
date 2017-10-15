#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int r;
int c;
char grid[100][100];
int solve()
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
    if (grid[i][j] == '#')
  {
    if ((i == (r - 1)) || (j == (c - 1)))
      return 0;

    if (((grid[i][j + 1] != '#') || (grid[i + 1][j] != '#')) || (grid[i + 1][j + 1] != '#'))
      return 0;

    grid[i][j] = '/';
    grid[i][j + 1] = '\\';
    grid[i + 1][j] = '\\';
    grid[i + 1][j + 1] = '/';
  }



  for (i = 0; i < r; i++)
    printf("%s\n", grid[i]);

  return 1;
}

int main()
{
  int first_iteration;
  int t;
  int t_case;
  scanf("%d", &t_case);
  for (t = 1; t <= t_case; t++)
  {
    int i;
    scanf("%d %d", &r, &c);
    for (i = 0; i < r; i++)
      scanf("%s", grid[i]);

    printf("Case #%d:\n", t);
    if (!solve())
      printf("Impossible\n");

  }

  return 0;
}


