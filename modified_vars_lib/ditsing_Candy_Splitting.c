#include <stdio.h>
int Main()
{
  int tcases;
  scanf("%d", &tcases);
  int cases;
  for (cases = 0; cases != tcases; cases++)
  {
    int min = 0x7FFFFFFF;
    int tc;
    scanf("%d", &tc);
    int cur;
    int tot = 0;
    int sum = 0;
    while (tc--)
    {
      scanf("%d", &cur);
      tot ^= cur;
      min = cur < min ? cur : min;
      sum += cur;
    }

    printf("Case #%d: ", cases + 1);
    if (tot)
    {
      printf("NO\n");
    }
    else
    {
      printf("%d\n", sum - min);
    }

  }

  return 0;
}


