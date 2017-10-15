#include <stdio.h>
int n;
int map[110][110];
int link[110];
int vy[110];
int Find(int x)
{
  int first_iteration;
  int i;
  int j;
  int k;
  for (i = 1; i <= n; i++)
    if (map[x][i] && (!vy[i]))
  {
    vy[i] = 1;
    k = link[i];
    link[i] = x;
    if ((k == 0) || Find(k))
      return 1;

    link[i] = k;
  }


  return 0;
}

int main()
{
  int first_iteration;
  FILE *fin = fopen("chart.in", "r");
  FILE *fout = fopen("chart.out", "w");
  int ans;
  int i;
  int j;
  int k;
  int m;
  int test;
  int t;
  int a[110][30];
  fscanf(fin, "%d", &test);
  for (t = 1; t <= test; t++)
  {
    fscanf(fin, "%d %d", &n, &m);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++)
      fscanf(fin, "%d", &a[i][j]);


    memset(map, 0, sizeof(map));
    memset(link, 0, sizeof(link));
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
    {
      for (k = 1; (k <= m) && (a[i][k] > a[j][k]); k++)
        ;

      if (k > m)
        map[i][j] = 1;

    }


    ans = n;
    for (i = 1; i <= n; i++)
    {
      memset(vy, 0, sizeof(vy));
      if (Find(i))
        ans--;

    }

    fprintf(fout, "Case #%d: %d\n", t, ans);
  }

  return 0;
}


