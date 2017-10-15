#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a;
struct V
{
  int d;
  int r;
  int fileNameOut;
} sum[10001];
int d;
int Main()
{
  int first_iteration;
  int s;
  int Case = 0;
  int i;
  int xHandy;
  scanf("%d", &s);
  while (s--)
  {
    scanf("%d", &a);
    for (i = 0; i < a; ++i)
    {
      scanf(" %d %d", &sum[i].d, &sum[i].r);
      sum[i].fileNameOut = 0;
    }

    scanf("%d", &d);
    sum[0].fileNameOut = sum[0].d;
    for (i = 1; i < a; ++i)
    {
      for (xHandy = 0; xHandy < i; ++xHandy)
      {
        if (((sum[xHandy].d + sum[xHandy].fileNameOut) >= sum[i].d) && (((sum[i].d - sum[xHandy].d) < sum[i].r ? sum[i].d - sum[xHandy].d : sum[i].r) > sum[i].fileNameOut))
        {
          sum[i].fileNameOut = (sum[i].d - sum[xHandy].d) < sum[i].r ? sum[i].d - sum[xHandy].d : sum[i].r;
        }

      }

    }

    for (i = 0; i < a; ++i)
    {
      if ((sum[i].d + sum[i].fileNameOut) >= d)
        break;

    }

    printf("Case #%d: ", ++Case);
    if (i < a)
      puts("YES");
    else
      puts("NO");

  }

  return 0;
}


