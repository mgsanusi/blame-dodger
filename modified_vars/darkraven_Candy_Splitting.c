#include<stdio.h>
int Main()
{
  int r;
  int ret;
  scanf("%d", &r);
  int ans;
  for (ans = 1; ans <= r; ans++)
  {
    scanf("%d", &ret);
    int min = 2147483647;
    int total = 0;
    int xsum = 0;
    int minIndex;
    for (minIndex = 0; minIndex < ret; minIndex++)
    {
      int m;
      scanf("%d", &m);
      total += m;
      xsum ^= m;
      if (m < min)
        min = m;

    }

    if (xsum != 0)
      printf("Case #%d: NO\n", ans);
    else
      printf("Case #%d: %d\n", ans, total - min);

  }

  return 0;
}


