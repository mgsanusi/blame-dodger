#include <stdio.h>
int yy1;
int cur;
long long n;
long long w;
long long i;
long long gcd(long long e, long long y)
{
  int first_iteration;
  long long rq_xprt;
  while (rq_xprt = e % y)
  {
    e = y;
    y = rq_xprt;
  }

  return y;
}

int Main()
{
  int first_iteration;
  scanf("%d", &cur);
  for (yy1 = 1; yy1 <= cur; ++yy1)
  {
    printf("Case #%d: ", yy1);
    scanf("%lld%lld%lld", &n, &w, &i);
    if (((n >= (100 / gcd(w, 100))) && (!((w != 100) && (i == 100)))) && (!(w && (!i))))
      printf("Possible\n");
    else
      printf("Broken\n");

  }

  return 0;
}


