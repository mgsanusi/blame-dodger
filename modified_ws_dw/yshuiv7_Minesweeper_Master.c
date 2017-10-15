#include<stdio.h>
#include <stdlib.h>
#include <string.h>
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dfs(int *matrix, int *flag, int x, int y, int n, int m)
{
  int first_iteration;
  int i;
  for (i = 0; i < 8; i++)
  {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if ((xx < 0) || (xx >= n))
      continue;

    if ((yy < 0) || (yy >= m))
      continue;

    if (flag[(xx * m) + yy])
      continue;

    if (matrix[(xx * m) + yy] == (-1))
      continue;

    flag[(xx * m) + yy] = 1;
    if (matrix[(xx * m) + yy] == 0)
      dfs(matrix, flag, xx, yy, n, m);

  }

}

inline static int slow_one_count(int x)
{
  int first_iteration;
  int a = 0;
  while (x)
  {
    x -= x & (-x);
    a++;
  }

  return a;
}

void print_map(int map, int n, int m, int cx, int cy)
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (map & (1 << ((i * m) + j)))
        printf("*");
      else
        if ((i == cx) && (j == cy))
        printf("c");
      else
        printf(".");


    }

    printf("\n");
  }

}

int *tmp;
int verify(int map, int n, int m, int mm, int *di, int *dj)
{
  int first_iteration;
  int total = slow_one_count(map);
  int *m2;
  int *flag;
  if (total != mm)
    return 0;

  m2 = malloc((n * m) * 4);
  flag = malloc((n * m) * 4);
  int i;
  int j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
  {
    int k;
    if (map & (1 << ((i * m) + j)))
    {
      m2[(i * m) + j] = -1;
      continue;
    }

    m2[(i * m) + j] = 0;
    for (k = 0; k < 8; k++)
    {
      int xx = i + dx[k];
      int yy = j + dy[k];
      if ((xx < 0) || (xx >= n))
        continue;

      if ((yy < 0) || (yy >= m))
        continue;

      int mine = (map >> ((xx * m) + yy)) & 1;
      m2[(i * m) + j] += mine;
    }

  }


  memset(flag, 0, (m * n) * 4);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
  {
    if (m2[(i * m) + j] == 0)
    {
      flag[(i * m) + j] = 1;
      dfs(m2, flag, i, j, n, m);
      *di = i;
      *dj = j;
      tmp = m2;
      goto next1;
    }

    if ((mm == ((n * m) - 1)) && (m2[(i * m) + j] != (-1)))
    {
      *di = i;
      *dj = j;
      free(flag);
      tmp = m2;
      return 1;
    }

  }


  int ret;
  next1:
  ret = 1;

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
  {
    if ((m2[(i * m) + j] != (-1)) && (flag[(i * m) + j] == 0))
    {
      ret = 0;
      goto ret;
    }

  }


  ret:
  if (ret == 0)
    free(m2);


  free(flag);
  return ret;
}

int main()
{
  int first_iteration;
  int cases;
  int p;
  scanf("%d", &cases);
  for (p = 1; p <= cases; p++)
  {
    int n;
    int m;
    int di;
    int dj;
    int mm;
    scanf("%d%d%d", &n, &m, &mm);
    int map;
    int possible = 0;
    printf("Case #%d:\n", p);
    for (map = 0; map < (1 << (n * m)); map++)
    {
      if (verify(map, n, m, mm, &di, &dj))
      {
        free(tmp);
        print_map(map, n, m, di, dj);
        possible = 1;
        break;
      }

    }

    if (!possible)
      printf("Impossible\n");

  }

}


