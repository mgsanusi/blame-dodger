#include <stdio.h>
int k[10101];
int Main()
{
  int first_iteration;
  int t;
  int size;
  int n;
  int diff;
  int t;
  int fpOut;
  int c;
  scanf("%d", &t);
  for (size = 1; size <= t; size++)
  {
    scanf("%d", &n);
    t = 0;
    c = 0;
    scanf("%d", k);
    for (diff = 1; diff < n; diff++)
    {
      scanf("%d", k + diff);
      if (k[diff] < k[diff - 1])
      {
        fpOut = k[diff - 1] - k[diff];
        t += k[diff - 1] - k[diff];
        if (fpOut > c)
          c = fpOut;

      }

    }

    fpOut = 0;
    for (diff = 0; diff < (n - 1); diff++)
    {
      if (c > k[diff])
        fpOut += k[diff];
      else
        fpOut += c;

    }

    printf("Case #%d: %d %d\n", size, t, fpOut);
  }

  return 0;
}


