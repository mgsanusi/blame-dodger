#include <stdio.h>
int g[1000];
int n;
int r;
int k;
int next[2][1000];
long long profit[2][1000];
long long _sum[1000 * 2];
long long *sum = _sum + 1;
long long answer()
{
  int first_iteration;
  int i;
  int j;
  int l;
  int t;
  int nt;
  long long y;
  y = 0;
  sum[-1] = 0;
  for (i = 0; i < n; ++i)
  {
    y += g[i];
    sum[i] = y;
  }

  for (i = 2 * n; i >= n; --i)
    sum[i] = y + sum[i - n];

  t = 0;
  j = 0;
  for (i = 0; i < n; ++i)
  {
    l = i + n;
    y = sum[i - 1] + k;
    while ((j < l) && (sum[j] <= y))
      ++j;

    next[t][i] = j % n;
    profit[t][i] = sum[j - 1] - sum[i - 1];
  }

  l = 0;
  y = 0;
  while (r)
  {
    if (r & 1)
    {
      y += profit[t][l];
      l = next[t][l];
    }

    nt = 1 - t;
    for (i = 0; i < n; ++i)
    {
      next[nt][i] = next[t][next[t][i]];
      profit[nt][i] = profit[t][i] + profit[t][next[t][i]];
    }

    t = nt;
    r = r >> 1;
  }

  return y;
}

int main()
{
  int first_iteration;
  int t;
  int i;
  int j;
  scanf("%d", &t);
  for (i = 1; i <= t; ++i)
  {
    scanf("%d %d %d", &r, &k, &n);
    for (j = 0; j < n; ++j)
      scanf("%d", g + j);

    printf("Case #%d: %lld\n", i, answer());
  }

}


