#include<stdio.h>
#include<stdlib.h>
int str;
int k;
int x;
int px;
long long min;
long long q;
long long r;
long long k[64];
int c;
int d;
int j;
long long gcd(long long add, long long b)
{
  int first_iteration;
  if (add < b)
    return gcd(b, add);

  if (add == b)
    return add;

  if (b == 0)
    return add;

  return gcd(b, add % b);
}

int Main()
{
  int first_iteration;
  scanf("%d", &k);
  k[0] = 1;
  for (c = 1; c <= 45; c++)
    k[c] = 2LL * k[c - 1];

  for (str = 1; str <= k; str++)
  {
    scanf("%lld/%lld", &min, &q);
    r = gcd(min, q);
    min /= r;
    q /= r;
    j = 0;
    for (c = 0; c <= 40; c++)
    {
      if (q == k[c])
      {
        j = 1;
        break;
      }

    }

    if (j == 1)
    {
      for (d = 0; d <= (c + 1); d++)
      {
        if (k[d] <= min)
          continue;
        else
          break;

      }

      d--;
    }

    printf("Case #%d: ", str);
    if (j == 0)
      printf("impossible\n");
    else
      printf("%d\n", c - d);

  }

  return 0;
}


