#include <stdio.h>
#include <string.h>
int y[10008];
int x[10008];
int fg1[10008];
int Main()
{
  int c;
  int m;
  int n;
  int tc;
  int ans = 0;
  int tmp;
  int r;
  int where;
  scanf("%d", &c);
  for (m = 1; m <= c; m++)
  {
    ans = 0;
    scanf("%d", &n);
    for (r = 0; r < n; r++)
    {
      scanf("%d%d", &y[r], &x[r]);
    }

    scanf("%d", &tc);
    memset(fg1, -1, sizeof(fg1));
    fg1[0] = y[0] * 2;
    for (r = 0; r < n; r++)
    {
      if (fg1[r] >= tc)
      {
        ans = 1;
        break;
      }

      where = r + 1;
      while ((where < n) && (y[where] <= fg1[r]))
      {
        tmp = x[where] < (y[where] - y[r]) ? x[where] : y[where] - y[r];
        fg1[where] = fg1[where] > (y[where] + tmp) ? fg1[where] : y[where] + tmp;
        where++;
      }

    }

    printf("Case #%d: %s\n", m, ans ? "YES" : "NO");
  }

  return 0;
}


