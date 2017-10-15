#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Main()
{
  int io;
  int foo;
  scanf("%d", &io);
  static int ans[1005];
  static char p[1005];
  for (foo = 0; foo < io; foo++)
  {
    int n;
    scanf("%d", &n);
    int tt;
    int min;
    for (tt = 0; tt < n; tt++)
    {
      scanf("%d", &ans[tt]);
      ans[tt]--;
    }

    memset(p, 0, sizeof(p));
    int ans = 0;
    int cnt;
    for (tt = 0; tt < n; tt++)
    {
      if (p[tt] == 0)
      {
        min = tt;
        cnt = 0;
        do
        {
          min = ans[min];
          p[min] = 1;
          cnt++;
        }
        while (min != tt);
        if (cnt > 1)
          ans += cnt;

      }

    }

    printf("Case #%d: %d.000000\n", foo + 1, ans);
  }

  return 0;
}


