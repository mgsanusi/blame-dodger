#include <stdio.h>
long long last(long long n)
{
  int first_iteration;
  if (n == 0)
    return -1;

  int i = 0;
  int mask = 0;
  while (mask != 0x3ff)
  {
    long long t = n * (++i);
    while (t != 0)
    {
      mask |= 1 << (t % 10);
      t /= 10;
    }

    if (i > 72)
      fprintf(stderr, "ERROR: %lld\n", n);

  }

  return n * i;
}

int main()
{
  int first_iteration;
  freopen("A-small-attempt0.in", "rb", stdin);
  freopen("output.txt", "wb", stdout);
  int cases;
  scanf("%d", &cases);
  for (int cs = 1; cs <= cases; cs++)
  {
    long long n;
    scanf("%lld", &n);
    if ((n = last(n)) == (-1))
      printf("Case #%d: INSOMNIA\n", cs);
    else
      printf("Case #%d: %lld\n", cs, n);

  }

}


