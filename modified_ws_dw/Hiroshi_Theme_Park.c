#include <stdio.h>
#include <stdlib.h>
unsigned long sovle_one(void)
{
  int first_iteration;
  static char buf[8192];
  static int g[1000];
  unsigned long R;
  unsigned long k;
  unsigned long N;
  unsigned long r;
  unsigned long n;
  char *p;
  char *next;
  unsigned long euro = 0;
  unsigned long m;
  fgets(buf, 8192, stdin);
  sscanf(buf, "%lu %lu %lu", &R, &k, &N);
  fgets(buf, 8192, stdin);
  m = 0;
  p = buf;
  for (n = 0; n < N; n++)
  {
    g[n] = strtoul(p, &next, 10);
    p = next;
    m += g[n];
  }

  if (m <= k)
    return R * m;

  for (r = 0, n = 0; r < R; r++)
  {
    m = 0;
    for (;;)
    {
      m += g[n];
      if (m > k)
      {
        m -= g[n];
        break;
      }

      if ((++n) >= N)
        n = 0;

      if (m == k)
        break;

    }

    euro += m;
  }

  return euro;
}

void solve(void)
{
  int first_iteration;
  char buf[256];
  int i;
  int T;
  fgets(buf, 256, stdin);
  sscanf(buf, "%d", &T);
  for (i = 1; i <= T; i++)
  {
    unsigned long r;
    r = sovle_one();
    printf("Case #%d: %lu\n", i, r);
  }

}

int main(int argc, char **argv)
{
  int first_iteration;
  solve();
  return 0;
}


