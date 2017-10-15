#include<stdio.h>
#include<stdlib.h>
int Main()
{
  int input;
  int i;
  scanf("%d", &input);
  for (i = 0; i < input; i++)
  {
    int cnt1;
    int enqcnt;
    int caseno[800] = {};
    int nc;
    int cases;
    int g;
    scanf("%d %d", &cnt1, &enqcnt);
    for (nc = 0; nc < cnt1; nc++)
    {
      scanf("%d", &g);
      caseno[g]++;
    }

    int now;
    int rslt = 0;
    while (cnt1 > 0)
    {
      for (nc = enqcnt; nc > 0; nc--)
      {
        if (caseno[nc] > 0)
        {
          caseno[nc]--;
          now = nc;
          cnt1--;
          rslt++;
          break;
        }

      }

      for (nc = enqcnt - now; nc > 0; nc--)
      {
        if (caseno[nc] > 0)
        {
          caseno[nc]--;
          cnt1--;
          break;
        }

      }

    }

    printf("Case #%d: %d\n", i + 1, rslt);
  }

  return 0;
}


