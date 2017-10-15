#include <stdio.h>

#define MAXN 1000

int g[MAXN];
int n, r, k;
int next[2][MAXN];
long long profit[2][MAXN];
long long _sum[MAXN * 2], *sum = _sum + 1;

long long answer() {
  int i, j, l, t, nt;
  long long y;

  y = 0; sum[-1] = 0;
  for (i = 0; i < n; ++i) {
    y += g[i];
    sum[i] = y;
  }
  for (i = 2 * n; i >= n; --i)
    sum[i] = y + sum[i - n];

  t = 0; j = 0;
  for (i = 0; i < n; ++i) {
    l = i + n;
    y = sum[i - 1] + k;
    while (j < l && sum[j] <= y)
      ++j;
    next[t][i] = j % n;
    profit[t][i] = sum[j - 1] - sum[i - 1];
  }

  l = 0; y = 0;
  while (r) {
    if (r & 1) {
      y += profit[t][l];
      l = next[t][l];
    }
    nt = 1 - t;
    for (i = 0; i < n; ++i) {
      next[nt][i] = next[t][next[t][i]];
      profit[nt][i] = profit[t][i] + profit[t][next[t][i]];
    }
    t = nt;
    r = (r >> 1);
  }

  return y;
}

int main() {
  int t, i, j;

  scanf("%d", &t);
  for (i = 1; i <= t; ++i) {
    scanf("%d %d %d", &r, &k, &n);
    for (j = 0; j < n; ++j)
      scanf("%d", g+j);
    printf("Case #%d: %lld\n", i, answer());
  }
}
