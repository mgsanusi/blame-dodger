#include <stdio.h>
int Main()
{
  int first_iteration;
  int s[8];
  int dataset_num;
  int tt2;
  int k;
  int a;
  int b;
  int bc;
  int e;
  int tmp;
  int bot;
  int buf;
  int fg;
  int f;
  int n;
  scanf("%d", &tt2);
  for (k = 1; k <= tt2; k++)
  {
    scanf("%d%d", &a, &b);
    tmp = a;
    bc = (n = 0);
    while (tmp > 0)
    {
      tmp /= 10;
      bc++;
    }

    e = 1;
    for (bot = 1; bot < bc; bot++)
      e *= 10;

    for (bot = a; bot <= b; bot++)
    {
      tmp = bot;
      s[0] = bot;
      dataset_num = 1;
      for (buf = 1; buf < bc; buf++)
      {
        tmp = ((tmp % 10) * e) + (tmp / 10);
        if (tmp > b)
          continue;

        if (tmp <= bot)
          continue;

        f = 1;
        for (fg = 0; fg < dataset_num; fg++)
        {
          if (s[fg] == tmp)
          {
            f = 0;
            break;
          }

        }

        if (f)
        {
          s[dataset_num++] = tmp;
          n++;
        }

      }

    }

    printf("Case #%d: %d\n", k, n);
  }

  return 0;
}


