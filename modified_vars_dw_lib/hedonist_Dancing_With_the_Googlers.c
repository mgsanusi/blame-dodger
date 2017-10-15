#include <stdio.h>
int Main()
{
  int first_iteration;
  int gssCMaNotDfltMech;
  int n;
  int s;
  int p;
  int tcase;
  int res;
  int low;
  int high;
  int stSize;
  int time;
  scanf("%d", &gssCMaNotDfltMech);
  for (tcase = 0; tcase < gssCMaNotDfltMech; tcase++)
  {
    printf("Case #%d: ", tcase + 1);
    scanf("%d %d %d", &n, &s, &p);
    high = (p * 3) - 2;
    low = (p * 3) - 4;
    if (high < p)
      high = p;

    if (low < p)
      low = p;

    time = 0;
    for (res = 0; res < n; res++)
    {
      scanf("%d", &stSize);
      if (stSize >= high)
        time++;
      else
        if ((stSize >= low) && (s > 0))
      {
        s--;
        time++;
      }


    }

    printf("%d\n", time);
  }

  return 0;
}


