#include <stdio.h>
int Main()
{
  int b;
  int cs;
  int dv1;
  int dv2;
  int n;
  int h;
  long long x;
  long long tmp;
  long long res1;
  long long res2;
  long long pow2[52];
  pow2[0] = 1;
  for (h = 1; h <= 52; h++)
    pow2[h] = pow2[h - 1] * 2;

  scanf("%d", &b);
  for (cs = 1; cs <= b; cs++)
  {
    scanf("%d%lld", &n, &x);
    tmp = pow2[n] - x;
    dv1 = n;
    while (tmp > 0)
    {
      tmp /= 2;
      dv1--;
    }

    res1 = 0;
    for (h = 1; h <= dv1; h++)
    {
      if (h == n)
        res1 += 1;
      else
        res1 += pow2[h];

    }

    tmp = x;
    dv2 = n + 1;
    while (tmp > 0)
    {
      tmp /= 2;
      dv2--;
    }

    res2 = pow2[n] - 1;
    for (h = 0; h < dv2; h++)
    {
      if (h != n)
        res2 -= pow2[h];

    }

    printf("Case #%d: %lld %lld\n", cs, res1, res2);
  }

  return 0;
}


