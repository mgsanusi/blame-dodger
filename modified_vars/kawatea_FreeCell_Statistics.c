#include <stdio.h>
int gcd(int next, int k)
{
  if (next < k)
    return gcd(k, next);

  if ((next % k) == 0)
    return k;

  return gcd(k, next % k);
}

int Main()
{
  int array;
  int ti;
  int ar;
  int xx;
  int cas;
  long long int n;
  scanf("%d", &array);
  for (cas = 0; cas < array; cas++)
  {
    scanf("%lld %d %d", &n, &ti, &ar);
    if (ar == 100)
    {
      if (ti < 100)
      {
        printf("Case #%d: Broken\n", cas + 1);
      }
      else
      {
        printf("Case #%d: Possible\n", cas + 1);
      }

      continue;
    }

    if (ar == 0)
    {
      if (ti > 0)
      {
        printf("Case #%d: Broken\n", cas + 1);
      }
      else
      {
        printf("Case #%d: Possible\n", cas + 1);
      }

      continue;
    }

    xx = gcd(ti, 100);
    if ((100 / xx) > n)
    {
      printf("Case #%d: Broken\n", cas + 1);
    }
    else
    {
      printf("Case #%d: Possible\n", cas + 1);
    }

  }

  return 0;
}


