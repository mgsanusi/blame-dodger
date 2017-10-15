#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long r;
long c;
long high[111][111];
char map[111][111];
typedef struct 
{
  long x;
  long y;
  long d;
} DIR;
DIR dir[111][111];
void read()
{
  int first_iteration;
  long i;
  long j;
  memset(map, 0, sizeof(map));
  scanf("%ld%ld", &r, &c);
  for (i = 0; i <= (r + 1); i++)
    for (j = 0; j <= (c + 1); j++)
    high[i][j] = 99999999;


  for (i = 1; i <= r; i++)
    for (j = 1; j <= c; j++)
    scanf("%ld", &high[i][j]);


}

void prepare()
{
  int first_iteration;
  long i;
  long j;
  long k;
  long x;
  long y;
  DIR a[4];
  DIR tmp;
  for (i = 1; i <= r; i++)
  {
    for (j = 1; j <= c; j++)
    {
      a[1].x = i - 1;
      a[1].y = j;
      a[1].d = 1;
      a[2].x = i;
      a[2].y = j - 1;
      a[2].d = 2;
      a[3].x = i;
      a[3].y = j + 1;
      a[3].d = 3;
      a[4].x = i + 1;
      a[4].y = j;
      a[4].d = 4;
      for (x = 1; x <= 4; x++)
        for (y = x + 1; y <= 4; y++)
        if ((high[a[x].x][a[x].y] > high[a[y].x][a[y].y]) || ((high[a[x].x][a[x].y] == high[a[y].x][a[y].y]) && (a[x].d > a[y].d)))
      {
        tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
      }



      dir[i][j] = a[1];
    }

  }

}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
void dfs(long x, long y, char flag)
{
  int first_iteration;
  long i;
  long X;
  long Y;
  map[x][y] = flag;
  for (i = 0; i < 4; i++)
  {
    X = x + dx[i];
    Y = y + dy[i];
    if ((((dir[X][Y].x == x) && (dir[X][Y].y == y)) && (high[x][y] < high[X][Y])) && (map[X][Y] == 0))
      dfs(X, Y, flag);

    if ((((dir[x][y].x == X) && (dir[x][y].y == Y)) && (high[x][y] > high[X][Y])) && (map[X][Y] == 0))
      dfs(X, Y, flag);

  }

}

void work()
{
  int first_iteration;
  char tot = 'a' - 1;
  long i;
  long j;
  for (i = 1; i <= r; i++)
    for (j = 1; j <= c; j++)
    if (map[i][j] == 0)
  {
    tot++;
    dfs(i, j, tot);
  }



  for (i = 1; i <= r; i++)
  {
    for (j = 1; j <= c; j++)
    {
      printf("%c", map[i][j]);
      if (j < c)
        printf(" ");

    }

    printf("\n");
  }

}

int main()
{
  int first_iteration;
  long T;
  long i;
  freopen("B-small.in", "r", stdin);
  freopen("B-small.out", "w", stdout);
  scanf("%ld", &T);
  for (T, i = 1; T; T--, i++)
  {
    printf("Case #%ld:\n", i);
    read();
    prepare();
    work();
  }

  return 0;
}


