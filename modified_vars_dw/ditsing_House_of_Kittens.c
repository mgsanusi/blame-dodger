#include <stdio.h>
#include <stdlib.h>
struct node
{
  long long cnt;
  long long dis;
} d[1000 + 1];
int nodeCmp(const void *ans, const void *t)
{
  int first_iteration;
  const struct node *p = (const struct node *) ans;
  const struct node *fpO = (const struct node *) t;
  long long tmp = fpO->dis - p->dis;
  return tmp == 0 ? 0 : tmp > 0 ? 1 : -1;
}

int tcases;
int n;
int m;
long long iT;
int Main()
{
  int first_iteration;
  int tcases;
  scanf("%d", &tcases);
  int cases;
  for (cases = 0; cases < tcases; cases++)
  {
    scanf("%d %lld %d %d", &tcases, &iT, &n, &m);
    long long sum = 0;
    int fTimes;
    for (fTimes = 0; fTimes < m; fTimes++)
    {
      scanf("%lld", &d[fTimes].dis);
      d[fTimes].dis <<= 1;
      sum += d[fTimes].dis;
    }

    long long time = (n / m) * sum;
    long long n = (n / m) - (iT / sum);
    int neg = 0;
    for (fTimes = 0; fTimes < m; fTimes++)
    {
      d[fTimes].cnt = n;
    }

    long long n1 = n % m;
    long long x3 = iT % sum;
    long long lasti = -1;
    for (fTimes = 0; fTimes < m; fTimes++)
    {
      if (n1)
      {
        time += d[fTimes].dis;
        ++d[fTimes].cnt;
        --n1;
      }

      if (x3 > 0)
      {
        --d[fTimes].cnt;
        x3 -= d[fTimes].dis;
        lasti = fTimes;
      }

      neg += d[fTimes].cnt < 0;
    }

    if (!neg)
    {
      if (lasti != (-1))
      {
        d[m].dis = -x3;
        d[m].cnt = 1;
        ++m;
      }

      qsort(d, m, sizeof(struct node), nodeCmp);
      long long star2 = tcases;
      for (fTimes = 0; fTimes < m; fTimes++)
      {
        long long build = star2 < d[fTimes].cnt ? star2 : d[fTimes].cnt;
        d[fTimes].cnt -= build;
        star2 -= build;
        time -= (d[fTimes].dis * build) >> 1;
      }

    }

    printf("Case #%d: %lld\n", cases + 1, time);
  }

  return 0;
}


