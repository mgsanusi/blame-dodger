#include<stdio.h>
long long seech();
long long score(long long tim);
int ans;
int k;
long long foo[1024];
long long best;
int start;
int a;
long long tmp;
int Main()
{
  scanf("%d", &k);
  for (ans = 1; ans <= k; ans++)
  {
    scanf("%d", &a);
    scanf("%lld", &best);
    for (start = 0; start < a; start++)
    {
      scanf("%lld", &foo[start]);
    }

    tmp = seech();
    best -= score(tmp);
    for (start = 0; start < a; start++)
    {
      if ((tmp % foo[start]) == 0)
        best--;

      if (best == 0)
        break;

    }

    printf("Case #%d: %d\n", ans, start + 1);
  }

  return 0;
}

long long score(long long tim)
{
  int st = 0;
  long long anstmp = 0;
  if (tim == 0)
    return 0;

  for (st = 0; st < a; st++)
  {
    anstmp += ((tim - 1) / foo[st]) + 1;
  }

  return anstmp;
}

long long seech()
{
  long long mintime;
  long long maxtime;
  long long midtime;
  if (score(1) >= best)
    return 0;

  mintime = 0;
  maxtime = (foo[0] * best) + 2LL;
  while (maxtime >= mintime)
  {
    midtime = (mintime + maxtime) / 2LL;
    if (mintime > maxtime)
      return mintime;

    if (score(midtime) < best)
      mintime = midtime;
    else
      maxtime = midtime;

    if ((score(mintime) < best) && (score(mintime + 1) >= best))
      return mintime;
    else
      mintime++;

    if (score(maxtime) < best)
      return maxtime;
    else
      maxtime--;

  }

  return -1000000;
}


