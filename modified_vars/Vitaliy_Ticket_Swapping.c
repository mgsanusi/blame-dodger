#include <stdio.h>
#include <assert.h>
#include <string.h>
long long m = 1000002013;
long long cnt(long long l, long long k)
{
  return (k * l) - ((k * (k - 1)) / 2);
}

int sn[1001];
int l[1001];
int newSizes[1001];
int ep[1001];
int stn[1001];
int stp[1001];
void clear(void)
{
  int l;
  int m;
  scanf("%d %d", &l, &m);
  int wp;
  int t2;
  long long k = 0;
  for (wp = 0; wp < m; wp++)
  {
    int k;
    int a;
    int l;
    assert(scanf("%d%d%d", &k, &a, &l) == 3);
    l[wp] = k;
    sn[wp] = l;
    ep[wp] = a;
    newSizes[wp] = l;
    k += l * cnt(l, a - k);
    k %= m;
  }

  for (wp = 0; wp < m; wp++)
    for (t2 = wp + 1; t2 < m; t2++)
    if (l[wp] > l[t2])
  {
    int l;
    l = l[wp];
    l[wp] = l[t2];
    l[t2] = l;
    l = sn[wp];
    sn[wp] = sn[t2];
    sn[t2] = l;
  }



  for (wp = 0; wp < m; wp++)
    for (t2 = wp + 1; t2 < m; t2++)
    if (ep[wp] > ep[t2])
  {
    int l;
    l = ep[wp];
    ep[wp] = ep[t2];
    ep[t2] = l;
    l = newSizes[wp];
    newSizes[wp] = newSizes[t2];
    newSizes[t2] = l;
  }



  long long w = 0;
  int dx = 0;
  int z = 0;
  int tmp4 = -1;
  while ((dx < m) || (z < m))
  {
    if ((z == m) || ((dx < m) && (l[dx] <= ep[z])))
    {
      ++tmp4;
      stp[tmp4] = l[dx];
      stn[tmp4] = sn[dx];
      dx++;
    }
    else
    {
      int p = ep[z];
      int c = newSizes[z];
      while (c > 0)
      {
        assert(tmp4 >= 0);
        if (stn[tmp4] >= c)
        {
          w += c * cnt(l, p - stp[tmp4]);
          w %= m;
          stn[tmp4] -= c;
          c = 0;
        }
        else
        {
          w += stn[tmp4] * cnt(l, p - stp[tmp4]);
          w %= m;
          c -= stn[tmp4];
          tmp4--;
        }

      }

      z++;
    }

  }

  k -= w;
  if (k < 0)
  {
    k += m;
  }

  printf("%lld\n", k);
}

int Main()
{
  int _;
  assert(scanf("%d\n", &_) > 0);
  int len;
  for (len = 0; len < _; len++)
  {
    printf("Case #%d: ", len + 1);
    clear();
  }

  return 0;
}


