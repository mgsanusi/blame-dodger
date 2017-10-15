#include <stdio.h>
int new_puts(const char *str);

int Main()
{
  int q;
  int mididx;
  int curm;
  int s;
  int x[2000];
  int a[2000];
  scanf("%d", &q);
  for (mididx = 0; mididx < q; mididx++)
  {
    int n;
    int f = 0;
    scanf("%d", &n);
    for (curm = 0; curm < (n - 1); curm++)
    {
      scanf("%d", &x[curm]);
      x[curm]--;
    }

    printf("Case #%d:", mididx + 1);
    for (curm = 0; curm < (n - 1); curm++)
    {
      for (s = curm + 1; s < x[curm]; s++)
      {
        if (x[s] > x[curm])
        {
          f = 1;
          break;
        }

      }

      if (f == 1)
        break;

    }

    if (f == 1)
    {
      new_puts(" Impossible");
      continue;
    }

    for (curm = 0; curm < n; curm++)
      a[curm] = curm * 500000;

    for (curm = 0; curm < (n - 1); curm++)
    {
      int s;
      for (s = x[curm] - 1, s = 1; s > curm; s--, s++)
        a[s] -= s;

    }

    for (curm = 0; curm < n; curm++)
      printf(" %d", a[curm]);

    new_puts("");
  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}