#include<stdio.h>
int x;
int t;
int loops;
int foo[1024];
int tmp;
int qy;
int ans1;
int ans2;
int rate;
int Main()
{
  scanf("%d", &t);
  for (x = 1; x <= t; x++)
  {
    scanf("%d", &qy);
    for (tmp = 0; tmp < qy; tmp++)
    {
      scanf("%d", &foo[tmp]);
    }

    ans1 = 0;
    ans2 = 0;
    rate = 0;
    for (tmp = 1; tmp < qy; tmp++)
    {
      if (foo[tmp] < foo[tmp - 1])
        ans1 += foo[tmp - 1] - foo[tmp];

      if ((foo[tmp - 1] - foo[tmp]) > rate)
        rate = foo[tmp - 1] - foo[tmp];

    }

    for (tmp = 1; tmp < qy; tmp++)
    {
      if (foo[tmp - 1] < rate)
        ans2 += foo[tmp - 1];
      else
        ans2 += rate;

    }

    printf("Case #%d: %d %d\n", x, ans1, ans2);
  }

  return 0;
}


