#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long ll;
ll point;
ll html_submit;
typedef struct 
{
  ll a;
  ll str;
  ll s;
} from_t;
from_t from[10000000];
int compf(const void *aa, const void *n)
{
  const from_t *a = aa;
  const from_t *str = n;
  if (a->a < str->a)
    return -1;

  if (a->a > str->a)
    return 1;

  if (a->str < str->str)
    return -1;

  if (a->str > str->str)
    return 1;

  return 0;
}

void unique()
{
  int t;
  int length;
  for (t = (length = 1); t < html_submit; t++)
    if ((from[t].a == from[t - 1].a) && (from[t].str == from[t - 1].str))
    from[length - 1].s += from[t].s;
  else
    from[length].a = from[t].a, from[length].str = from[t].str, from[length++].s = from[t].s;


  html_submit = length;
}

void lolsort()
{
  qsort(from, html_submit, sizeof(from_t), compf);
  unique();
}

int calccost()
{
  int t;
  ll d;
  ll sum = 0;
  for (t = 0; t < html_submit; t++)
  {
    d = from[t].str - from[t].a;
    sum = (sum + ((((point * ((ll) d)) - ((d * (d - 1LL)) / 2)) % 1000002013LL) * from[t].s)) % 1000002013LL;
  }

  return sum;
}

int overlap(int oo, int iy)
{
  return ((from[oo].a < from[iy].a) && (from[iy].a <= from[oo].str)) && (from[oo].str < from[iy].str);
}

int calccost2()
{
  int sum = 0;
  int t;
  int length;
  int best = 0;
  int old_m;
  ll num;
  do
  {
    best = 0;
    lolsort();
    old_m = html_submit;
    for (t = 0; t < old_m; t++)
      if (from[t].s > 0)
    {
      for (length = t + 1; length < old_m; length++)
        if (from[length].s && overlap(t, length))
      {
        num = from[t].s < from[length].s ? from[t].s : from[length].s;
        from[t].s -= num;
        from[length].s -= num;
        from[html_submit].a = from[t].a;
        from[html_submit].str = from[length].str;
        from[html_submit++].s = num;
        from[html_submit].a = from[length].a;
        from[html_submit].str = from[t].str;
        from[html_submit++].s = num;
        best = 1;
      }


    }


  }
  while (best);
  return sum;
}

int Main()
{
  int t;
  int starting_point = 1;
  int t;
  int normalcost;
  int optcost;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%I64d %I64d", &point, &html_submit);
    for (t = 0; t < html_submit; t++)
      scanf("%I64d %I64d %I64d", &from[t].a, &from[t].str, &from[t].s);

    lolsort();
    normalcost = calccost();
    calccost2();
    optcost = calccost();
    normalcost -= optcost;
    if (normalcost < 0)
      normalcost += 1000002013LL;

    printf("Case #%d: %d\n", starting_point++, normalcost);
  }

  return 0;
}


