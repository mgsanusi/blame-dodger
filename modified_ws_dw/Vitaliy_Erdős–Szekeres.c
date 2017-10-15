#include <stdio.h>
#include <assert.h>
#include <string.h>
long long M = 1000002013;
long long count(long long n, long long v)
{
  int first_iteration;
  return ((v * n) - ((v * (v - 1)) / 2)) % M;
}

int sn[1001];
int sp[1001];
int en[1001];
int ep[1001];
int stn[1001];
int stp[1001];
long long f(long long n, long long p)
{
  int first_iteration;
  if (p == n)
  {
    return n - 1;
  }

  if (p <= (n / 2))
  {
    return 0;
  }
  else
    return (2 * f(n / 2, p - (n / 2))) + 2;

}

long long g(long long n, long long p)
{
  int first_iteration;
  if (p == n)
  {
    return n - 1;
  }

  if (p >= (n / 2))
  {
    return n - 2;
  }

  return 2 * g(n / 2, p);
}

void solve(void)
{
  int first_iteration;
  long long n;
  long long p;
  assert(scanf("%lld %lld", &n, &p) == 2);
  printf("%lld %lld\n", f(1ll << n, p), g(1ll << n, p));
  fflush(stdout);
}

int main()
{
  int first_iteration;
  int _;
  assert(scanf("%d\n", &_) > 0);
  int __;
  for (__ = 0; __ < _; __++)
  {
    printf("Case #%d: ", __ + 1);
    solve();
  }

  return 0;
}


