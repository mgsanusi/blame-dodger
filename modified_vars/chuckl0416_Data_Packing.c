#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int count;
int ans;
int total;
int n[1200];
int j;
int t;
int y;
int l;
int r;
int answer;
int minPos;
int mid;
int Main()
{
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  scanf("%d", &count);
  for (ans = 1; ans <= count; ans++)
  {
    printf("Case #%d: ", ans);
    scanf("%d", &total);
    for (j = 0; j < total; j++)
      scanf("%d", &n[j]);

    l = 0;
    r = total - 1;
    answer = 0;
    while (l <= r)
    {
      minPos = l;
      for (j = l + 1; j <= r; j++)
        if (n[j] < n[minPos])
        minPos = j;


      mid = (l + r) / 2;
      if (minPos <= mid)
      {
        for (t = minPos; t > l; t--)
        {
          n[t] = n[t - 1];
          answer++;
        }

        l++;
      }
      else
      {
        for (t = minPos; t < r; t++)
        {
          n[t] = n[t + 1];
          answer++;
        }

        r--;
      }

    }

    printf("%d\n", answer);
  }

  return 0;
}


