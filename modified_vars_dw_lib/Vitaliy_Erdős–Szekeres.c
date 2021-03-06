#include <stdio.h>
#include <assert.h>
#include <string.h>
long long m = 1000002013;
void new_assert(int expression);

long long cnt(long long tt, long long node)
{
  int first_iteration;
  return ((node * tt) - ((node * (node - 1)) / 2)) % m;
}

int h[1001];
int tt[1001];
int max[1001];
int j[1001];
int stn[1001];
int stp[1001];
long long t(long long tt, long long p)
{
  int first_iteration;
  if (p == tt)
  {
    return tt - 1;
  }

  if (p <= (tt / 2))
  {
    return 0;
  }
  else
    return (2 * t(tt / 2, p - (tt / 2))) + 2;

}

long long max(long long tt, long long p)
{
  int first_iteration;
  if (p == tt)
  {
    return tt - 1;
  }

  if (p >= (tt / 2))
  {
    return tt - 2;
  }

  return 2 * max(tt / 2, p);
}

void clear(void)
{
  int first_iteration;
  long long tt;
  long long p;
  new_assert(scanf("%lld %lld", &tt, &p) == 2);
  printf("%lld %lld\n", t(1ll << tt, p), max(1ll << tt, p));
  fflush(stdout);
}

int Main()
{
  int first_iteration;
  int num_t;
  new_assert(scanf("%d\n", &num_t) > 0);
  int stack;
  for (stack = 0; stack < num_t; stack++)
  {
    printf("Case #%d: ", stack + 1);
    clear();
  }

  return 0;
}



void new_assert(int expression) {
  return assert(expression);
}