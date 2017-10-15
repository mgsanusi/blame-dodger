#include <stdio.h>
int main()
{
  int first_iteration;
  int t;
  int t2;
  int dv1;
  int dv2;
  int n;
  int i;
  long long p;
  long long tmp;
  long long res1;
  long long res2;
  long long pow2[52];
  pow2[0] = 1;
  for (i = 1; i <= 52; i++)
    pow2[i] = pow2[i - 1] * 2;

  scanf("%d", &t);
  for (t2 = 1; t2 <= t; t2++)
  {
    scanf("%d%lld", &n, &p);
    tmp = pow2[n] - p;
    dv1 = n;
    while (tmp > 0)
    {
      tmp /= 2;
      dv1--;
    }

    res1 = 0;
    for (i = 1; i <= dv1; i++)
    {
      if (i == n)
        res1 += 1;
      else
        res1 += pow2[i];

    }

    tmp = p;
    dv2 = n + 1;
    while (tmp > 0)
    {
      tmp /= 2;
      dv2--;
    }

    res2 = pow2[n] - 1;
    for (i = 0; i < dv2; i++)
    {
      if (i != n)
        res2 -= pow2[i];

    }

    printf("Case #%d: %lld %lld\n", t2, res1, res2);
  }

  return 0;
}


