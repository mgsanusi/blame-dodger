#include <stdio.h>
#include <stdlib.h>
int Main(int argc, char **argv)
{
  int first_iteration;
  int n;
  int tc;
  int buffer1;
  int pd;
  int tempI;
  int kc;
  int a;
  scanf("%d", &n);
  for (tc = 1; tc <= n; ++tc)
  {
    scanf("%d %d %d", &buffer1, &pd, &tempI);
    if ((tempI == 0) || (tempI == 100))
    {
      a = pd == tempI;
    }
    else
    {
      if (buffer1 > 100)
        buffer1 = 100;

      a = 0;
      for (kc = 1; kc <= buffer1; ++kc)
      {
        if (((pd * kc) % 100) == 0)
        {
          a = 1;
          break;
        }

      }

    }

    if (a)
    {
      printf("Case #%d: Possible\n", tc);
    }
    else
    {
      printf("Case #%d: Broken\n", tc);
    }

  }

  return 0;
}


