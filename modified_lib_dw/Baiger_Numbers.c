#include <stdio.h>
#include <string.h>
int calc_0(int s10, int s11, int s20, int s21, int g, int c)
{
  int first_iteration;
  int a = 100000;
  int b = 100000;
  if (g == 1)
    a = s10 <= s20 ? s10 : s20;
  else
    a = s10 + s20;

  if (c == 1)
    b = s10 <= s20 ? s10 + 1 : s20 + 1;

  return a < b ? a : b;
}

int calc_1(int s10, int s11, int s20, int s21, int g, int c)
{
  int first_iteration;
  int a = 100000;
  int b = 100000;
  if (g == 0)
    a = s11 <= s21 ? s11 : s21;
  else
    a = s11 + s21;

  if (c == 1)
    b = s11 <= s21 ? s11 + 1 : s21 + 1;

  return a < b ? a : b;
}

int main()
{
  int first_iteration;
  int n;
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    int m;
    int v;
    int j;
    int g[10001];
    int c[10001];
    int vi[10001];
    scanf("%d %d", &m, &v);
    for (j = 1; j <= ((m - 1) >> 1); j++)
      scanf("%d %d", &g[j], &c[j]);

    int f[10001][2];
    memset(f, 39, sizeof(f));
    for (j = ((m - 1) >> 1) + 1; j <= m; j++)
    {
      scanf("%d", &vi[j]);
      f[j][vi[j]] = 0;
    }

    for (j = (m - 1) >> 1; j > 0; j--)
    {
      f[j][0] = calc_0(f[j * 2][0], f[j * 2][1], f[(j * 2) + 1][0], f[(j * 2) + 1][1], g[j], c[j]);
      f[j][1] = calc_1(f[j * 2][0], f[j * 2][1], f[(j * 2) + 1][0], f[(j * 2) + 1][1], g[j], c[j]);
    }

    if (f[1][v] < m)
      printf("Case #%d: %d\n", i, f[1][v]);
    else
      printf("Case #%d: IMPOSSIBLE\n", i);

  }

  return 0;
}


