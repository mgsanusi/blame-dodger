#include <stdio.h>
int main()
{
  int first_iteration;
  int s[8];
  int sn;
  int t;
  int k;
  int a;
  int b;
  int d;
  int e;
  int tmp;
  int i;
  int j;
  int l;
  int f;
  int r;
  scanf("%d", &t);
  for (k = 1; k <= t; k++)
  {
    scanf("%d%d", &a, &b);
    tmp = a;
    d = (r = 0);
    while (tmp > 0)
    {
      tmp /= 10;
      d++;
    }

    e = 1;
    for (i = 1; i < d; i++)
      e *= 10;

    for (i = a; i <= b; i++)
    {
      tmp = i;
      s[0] = i;
      sn = 1;
      for (j = 1; j < d; j++)
      {
        tmp = ((tmp % 10) * e) + (tmp / 10);
        if (tmp > b)
          continue;

        if (tmp <= i)
          continue;

        f = 1;
        for (l = 0; l < sn; l++)
        {
          if (s[l] == tmp)
          {
            f = 0;
            break;
          }

        }

        if (f)
        {
          s[sn++] = tmp;
          r++;
        }

      }

    }

    printf("Case #%d: %d\n", k, r);
  }

  return 0;
}


