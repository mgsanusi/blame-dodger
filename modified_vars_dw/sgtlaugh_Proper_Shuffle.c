#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int Main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int pa = 0;
  int p;
  int a;
  int y;
  int k;
  int mx;
  int tc;
  scanf("%d", &p);
  while (p--)
  {
    scanf("%d %d %d", &a, &y, &k);
    int counter = 0;
    for (mx = 0; mx < a; mx++)
    {
      for (tc = 0; tc < y; tc++)
      {
        int y2 = mx & tc;
        if (y2 < k)
          counter++;

      }

    }

    printf("Case #%d: %d\n", ++pa, counter);
  }

  return 0;
}


