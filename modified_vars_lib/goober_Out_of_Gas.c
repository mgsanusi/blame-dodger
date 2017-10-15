#include <stdio.h>
#include <string.h>
int max(int r, int p)
{
  return r > p ? r : p;
}

int min(int r, int p)
{
  return r < p ? r : p;
}

int Main()
{
  int y;
  scanf("%d", &y);
  for (int t = 1; t <= y; t++)
  {
    int n;
    scanf("%d", &n);
    int d[n + 1];
    int x2[n + 1];
    for (int rn = 0; rn < n; rn++)
      scanf("%d %d", &d[rn], &x2[rn]);

    int r;
    scanf("%d", &r);
    d[n] = r;
    x2[n] = r;
    int best[n + 1];
    memset(best, 0, sizeof(best));
    best[0] = d[0];
    best[n] = -1;
    for (int rn = 0; rn < n; rn++)
      for (int bases = rn + 1; (bases <= n) && ((d[bases] - d[rn]) <= best[rn]); bases++)
      best[bases] = min(max(best[bases], d[bases] - d[rn]), x2[bases]);


    printf("Case #%d: %s\n", t, best[n] >= 0 ? "YES" : "NO");
  }

  return 0;
}


