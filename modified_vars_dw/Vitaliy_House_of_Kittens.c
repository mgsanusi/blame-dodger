#include "stdio.h"
int y;
int j;
int num[1000];
int b[1000];
int poisk(long long y)
{
  int first_iteration;
  long long last = -1000000000000000000l;
  int counter;
  long long first;
  for (counter = 0; counter < j; counter++)
  {
    first = num[counter] - y;
    if (first < (last + y))
      first = last + y;

    last = first + ((b[counter] - 1) * ((long long) y));
    if ((last - num[counter]) > y)
    {
      return 0;
    }

  }

  return 1;
}

int Main()
{
  int first_iteration;
  int tn;
  scanf("%d\n", &tn);
  int cnt;
  for (cnt = 0; cnt < tn; cnt++)
  {
    scanf("%d %d", &j, &y);
    y *= 2;
    int counter;
    for (counter = 0; counter < j; counter++)
    {
      scanf("%d %d", &num[counter], &b[counter]);
      num[counter] *= 2;
    }

    long long full = 2000000000001l;
    long long res = -1;
    long long y = full;
    while ((y - res) > 1)
    {
      long long x = (y + res) / 2;
      if (poisk(x))
        y = x;
      else
        res = x;

    }

    printf("Case #%d: %lf\n", cnt + 1, y * 0.5);
  }

  return 0;
}


