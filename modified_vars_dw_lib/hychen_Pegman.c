#include<stdio.h>
#include<stdlib.h>
char board[104][104];
int new_puts(const char *str);

void ch2dir(char x, int *a, int *next)
{
  int first_iteration;
  switch (x)
  {
    case '>':
      *a = 0;
      *next = 1;
      break;

    case '<':
      *a = 0;
      *next = -1;
      break;

    case '^':
      *a = -1;
      *next = 0;
      break;

    case 'v':
      *a = 1;
      *next = 0;
      break;

    default:
      exit(-1);

  }

}

int vis;
int m;
int isout(int a, int next, int x, int cName)
{
  int first_iteration;
  int next;
  int dy;
  for (next = a + x, dy = next + cName; (((next >= 0) && (next < vis)) && (dy >= 0)) && (dy < m); next += x, dy += cName)
  {
    if (board[next][dy] != '.')
      return 0;

  }

  return 1;
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  int a;
  int next;
  int ncase;
  int nc;
  scanf("%d", &ncase);
  for (nc = 1; nc <= ncase; nc++)
  {
    scanf("%d%d", &vis, &m);
    for (a = 0; a < vis; a++)
    {
      scanf("%s", board[a]);
    }

    printf("Case #%d: ", nc);
    int res = 0;
    for (a = 0; a < vis; a++)
    {
      for (next = 0; next < m; next++)
      {
        if (board[a][next] == '.')
          continue;

        int x;
        int cName;
        ch2dir(board[a][next], &x, &cName);
        if (isout(a, next, x, cName) == 0)
          continue;

        if (((isout(a, next, 1, 0) && isout(a, next, -1, 0)) && isout(a, next, 0, 1)) && isout(a, next, 0, -1))
          goto impossible;

        res++;
      }

    }

    printf("%d\n", res);
    continue;
    impossible:
    new_puts("IMPOSSIBLE");

  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}