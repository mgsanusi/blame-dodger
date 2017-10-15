#include <stdio.h>
int g[55][55];
int n;
int list[111][55];
int taken[111];
int foundx[55];
int foundy[55];
int snoob(int x)
{
  int first_iteration;
  int s = x & (-x);
  int r = x + s;
  int o = x ^ r;
  o = (o >> 2) / s;
  return r | o;
}

int find(int x, int y, int dx, int dy)
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < ((2 * n) - 1); i++)
    if (!taken[i])
  {
    for (j = 0; j < n; j++)
      if (list[i][j] != g[x + (dx * j)][y + (dy * j)])
      goto fail;


    taken[i] = 1;
    return 1;
    fail:
    ;

  }


  return 0;
}

int check()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int t;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    if ((i != j) && (g[i][0] == g[j][0]))
    return 0;



  for (i = 0; i < (n - 1); i++)
    for (j = 0; j < (n - 1); j++)
    if (g[j][0] > g[j + 1][0])
    for (k = 0; k < n; k++)
    t = g[j][k], g[j][k] = g[j + 1][k], g[j + 1][k] = t;




  for (i = 0; i < n; i++)
  {
    for (j = 0; j < (n - 1); j++)
      if (g[i][j] > g[i][j + 1])
      return 0;


    for (j = 0; j < (n - 1); j++)
      if (g[j][i] > g[j + 1][i])
      return 0;


  }

  for (i = 0; i < ((2 * n) - 1); i++)
    taken[i] = 0;

  for (i = 0; i < n; i++)
    foundy[i] = find(i, 0, 0, 1);

  for (i = 0; i < n; i++)
    foundx[i] = find(0, i, 1, 0);

  for (i = (j = 0); i < ((2 * n) - 1); i++)
    j += taken[i];

  if (j < ((2 * n) - 1))
    return 0;

  for (i = 0; i < n; i++)
  {
    if (!foundy[i])
      for (j = 0; j < n; j++)
      printf(" %d", g[i][j]);


    if (!foundx[i])
      for (j = 0; j < n; j++)
      printf(" %d", g[j][i]);


  }

  putchar('\n');
  return 1;
}

void solve()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int mask;
  scanf("%d", &n);
  for (i = 0; i < ((n * 2) - 1); i++)
    for (j = 0; j < n; j++)
    scanf("%d", &list[i][j]);


  mask = (1 << n) - 1;
  first_iteration = 1;
  while ((!(mask & (1 << ((2 * n) - 1)))) || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    for (k = (i = 0); i < ((2 * n) - 1); i++)
      if (mask & (1 << i))
    {
      for (j = 0; j < n; j++)
        g[k][j] = list[i][j];

      k++;
    }


    if (check())
      break;

    mask = snoob(mask);
  }

}

int main()
{
  int first_iteration;
  int T;
  int caseno = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d:", caseno++), solve();

  return 0;
}


