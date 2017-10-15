#include<stdio.h>
int mp[600][600];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int st_x[1000000];
int st_y[1000000];
int st_size;
int new_puts(const char *str);
void nul(int a, int b)
{
  int first_iteration;
  int i;
  int j;
  int k;
  int ni;
  int nj;
  st_size = 1;
  st_x[0] = a;
  st_y[0] = b;
  mp[a][b] = 2;
  while (st_size)
  {
    i = st_x[st_size - 1];
    j = st_y[st_size - 1];
    st_size--;
    for (k = 0; k < 4; k++)
    {
      ni = i + dx[k];
      nj = j + dy[k];
      if ((((ni < 0) || (nj < 0)) || (ni >= 600)) || (nj >= 600))
        continue;

      if (mp[ni][nj])
        continue;

      mp[ni][nj] = 2;
      st_x[st_size] = ni;
      st_y[st_size] = nj;
      st_size++;
    }

  }

}

int chk(int a, int b)
{
  int first_iteration;
  int i;
  int j;
  i = (j = b);
  while (i >= 0)
  {
    if (mp[a][i] == 1)
      break;

    i--;
  }

  while (j < 600)
  {
    if (mp[a][j] == 1)
      break;

    j++;
  }

  if ((i >= 0) && (j < 600))
    return 1;

  i = (j = a);
  while (i >= 0)
  {
    if (mp[i][b] == 1)
      break;

    i--;
  }

  while (j < 600)
  {
    if (mp[j][b] == 1)
      break;

    j++;
  }

  if ((i >= 0) && (j < 600))
    return 1;

  return 0;
}

int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int q;
  int s;
  int len;
  int res;
  int size;
  int count = 0;
  char in[10000];
  int nx;
  int ny;
  int nd;
  scanf("%d", &size);
  while (size--)
  {
    for (i = 0; i < 600; i++)
      for (j = 0; j < 600; j++)
      mp[i][j] = 0;


    nx = (ny = 300);
    nd = 0;
    res = 0;
    scanf("%d", &q);
    while (q--)
    {
      scanf("%s%d", in, &s);
      for (i = 0;; i++)
        if (in[i] < ' ')
        break;


      len = i;
      while (s--)
      {
        for (i = 0; i < len; i++)
        {
          if (in[i] == 'R')
            nd = (nd + 1) % 4;

          if (in[i] == 'L')
            nd = (nd + 3) % 4;

          if (in[i] == 'F')
          {
            nx += dx[nd];
            ny += dy[nd];
            mp[nx][ny] = 1;
            nx += dx[nd];
            ny += dy[nd];
            mp[nx][ny] = 1;
          }

        }

      }

    }

    nul(0, 0);
    for (i = 1; i < 600; i += 2)
      for (j = 1; j < 600; j += 2)
      if (mp[i][j] == 2)
    {
      res += chk(i, j);
    }



    printf("Case #%d: %d\n", ++count, res);
  }

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


