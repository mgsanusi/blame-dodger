#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Main()
{
  int first_iteration;
  int t;
  int tCase;
  scanf("%d", &tCase);
  for (t = 1; t <= tCase; t++)
  {
    int n;
    int size;
    int tt;
    scanf("%d %d %d\n", &n, &size, &tt);
    int xpVerf;
    int min[1000];
    for (xpVerf = 0; xpVerf < n; xpVerf++)
      scanf("%d", &min[xpVerf]);

    int check;
    for (xpVerf = size; xpVerf <= tt; xpVerf++)
    {
      int j;
      check = 1;
      for (j = 0; j < n; j++)
        if (((min[j] % xpVerf) != 0) && ((xpVerf % min[j]) != 0))
      {
        check = 0;
        break;
      }


      if (check)
        break;

    }

    if (check)
      printf("Case #%d: %d\n", t, xpVerf);
    else
      printf("Case #%d: NO\n", t);

  }

  return 0;
}


