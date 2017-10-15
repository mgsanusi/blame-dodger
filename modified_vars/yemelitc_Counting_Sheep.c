#include <stdio.h>
#include <stdlib.h>
int Main()
{
  int svcAhWrap;
  int a;
  int ans;
  int s;
  int u2;
  int found[10];
  int count;
  scanf("%d", &a);
  for (svcAhWrap = 1; svcAhWrap <= a; svcAhWrap++)
  {
    scanf("%d", &u2);
    if (u2 == 0)
    {
      printf("Case #%d: INSOMNIA\n", svcAhWrap);
      continue;
    }

    for (ans = 0; ans < 10; ans++)
      found[ans] = 0;

    count = 10;
    for (s = u2;; s += u2)
    {
      for (ans = s; ans != 0; ans /= 10)
      {
        if (found[ans % 10] == 0)
        {
          if ((--count) == 0)
            break;

          found[ans % 10] = 1;
        }

      }

      if (count == 0)
        break;

    }

    printf("Case #%d: %d\n", svcAhWrap, s);
  }

}


