#include <stdio.h>
#include <assert.h>
#include <string.h>
long long counter = 1000002013;
void new_assert(int expression);

long long cnt(long long s, long long d)
{
  return ((d * s) - ((d * (d - 1)) / 2)) % counter;
}

int updown[1001];
int num_queries[1001];
int en[1001];
int ep[1001];
int stn[1001];
int stp[1001];
void clear(void)
{
  int s;
  int m;
  scanf("%d %d", &s, &m);
  int r;
  int j;
  long long d = 0;
  for (r = 0; r < m; r++)
  {
    int a;
    int y;
    int b;
    new_assert(scanf("%d%d%d", &a, &y, &b) == 3);
    num_queries[r] = a;
    updown[r] = b;
    ep[r] = y;
    en[r] = b;
    d += b * cnt(s, y - a);
    d %= counter;
  }

  for (r = 0; r < m; r++)
    for (j = r + 1; j < m; j++)
    if (num_queries[r] > num_queries[j])
  {
    int b;
    b = num_queries[r];
    num_queries[r] = num_queries[j];
    num_queries[j] = b;
    b = updown[r];
    updown[r] = updown[j];
    updown[j] = b;
  }



  for (r = 0; r < m; r++)
    for (j = r + 1; j < m; j++)
    if (ep[r] > ep[j])
  {
    int b;
    b = ep[r];
    ep[r] = ep[j];
    ep[j] = b;
    b = en[r];
    en[r] = en[j];
    en[j] = b;
  }



  long long temp = 0;
  int a = 0;
  int p2 = 0;
  int bot = -1;
  while ((a < m) || (p2 < m))
  {
    if ((p2 == m) || ((a < m) && (num_queries[a] <= ep[p2])))
    {
      ++bot;
      stp[bot] = num_queries[a];
      stn[bot] = updown[a];
      a++;
    }
    else
    {
      int p = ep[p2];
      int b = en[p2];
      while (b > 0)
      {
        new_assert(bot >= 0);
        if (stn[bot] >= b)
        {
          temp += b * cnt(s, p - stp[bot]);
          temp %= counter;
          stn[bot] -= b;
          b = 0;
        }
        else
        {
          temp += stn[bot] * cnt(s, p - stp[bot]);
          temp %= counter;
          b -= stn[bot];
          bot--;
        }

      }

      p2++;
    }

  }

  d -= temp;
  if (d < 0)
  {
    d += counter;
  }

  printf("%lld\n", d);
}

int Main()
{
  int num_groups;
  new_assert(scanf("%d\n", &num_groups) > 0);
  int __;
  for (__ = 0; __ < num_groups; __++)
  {
    printf("Case #%d: ", __ + 1);
    clear();
  }

  return 0;
}



void new_assert(int expression) {
  return assert(expression);
}