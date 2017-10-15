#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char count[128][128];
int add;
char xPutlong[1024][128];
int d;
int y2[1024][128];
int Main(void)
{
  char a[128];
  int nc;
  int h;
  int ans;
  int i;
  int dp;
  int p;
  gets(a);
  for (sscanf(a, "%d", &nc), h = 1; h <= nc; h++)
  {
    gets(a);
    sscanf(a, "%d", &add);
    for (i = 0; i < add; i++)
    {
      gets(count[i]);
    }

    memset(xPutlong, 0, sizeof(xPutlong));
    gets(a);
    sscanf(a, "%d", &d);
    for (i = 1; i <= d; i++)
    {
      gets(a);
      for (dp = 0; dp < add; dp++)
      {
        if (strcmp(a, count[dp]) == 0)
        {
          break;
        }

      }

      if (dp < add)
      {
        xPutlong[i][dp] = 1;
      }

    }

    for (dp = 0; dp < add; dp++)
    {
      y2[0][dp] = 0;
    }

    for (i = 1; i <= d; i++)
    {
      for (dp = 0; dp < add; dp++)
      {
        y2[i][dp] = 0x33333333;
        if (xPutlong[i][dp])
        {
          continue;
        }

        for (p = 0; p < add; p++)
        {
          y2[i][dp] = y2[i][dp] < (y2[i - 1][p] + 1) ? y2[i][dp] : y2[i - 1][p] + 1;
        }

        y2[i][dp] = y2[i][dp] < y2[i - 1][dp] ? y2[i][dp] : y2[i - 1][dp];
      }

    }

    ans = 0x33333333;
    for (dp = 0; dp < add; dp++)
    {
      if (y2[d][dp] < ans)
      {
        ans = y2[d][dp];
      }

    }

    printf("Case #%d: %d\n", h, ans);
  }

  return 0;
}


