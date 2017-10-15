#include <stdio.h>
int Main()
{
  int xPrivate;
  int n;
  int l;
  int sss;
  int i;
  int best;
  int s;
  int r[100];
  scanf("%d", &xPrivate);
  for (i = 0; i < xPrivate; i++)
  {
    int f = 0;
    scanf("%d %d %d", &n, &l, &sss);
    for (best = 0; best < n; best++)
      scanf("%d", &r[best]);

    for (best = l; best <= sss; best++)
    {
      for (s = 0; s < n; s++)
      {
        if (((best % r[s]) != 0) && ((r[s] % best) != 0))
        {
          break;
        }

      }

      if (s == n)
      {
        printf("Case #%d: %d\n", i + 1, best);
        f = 1;
        break;
      }

    }

    if (f == 0)
    {
      printf("Case #%d: NO\n", i + 1);
    }

  }

  return 0;
}


