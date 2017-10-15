#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Main()
{
  int iy;
  int t;
  scanf("%d", &t);
  static int k[1005];
  for (iy = 0; iy < t; iy++)
  {
    int minTime;
    int fontsLookup;
    int res = 0;
    int s = 0;
    int min = 2000000000;
    scanf("%d", &minTime);
    for (fontsLookup = 0; fontsLookup < minTime; fontsLookup++)
    {
      scanf("%d", &k[fontsLookup]);
      s += k[fontsLookup];
      if (k[fontsLookup] < min)
        min = k[fontsLookup];

      res ^= k[fontsLookup];
    }

    if (res)
      printf("Case #%d: NO\n", iy + 1);
    else
      printf("Case #%d: %d\n", iy + 1, s - min);

  }

  return 0;
}


