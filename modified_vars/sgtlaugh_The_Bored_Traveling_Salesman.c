#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct Pair
{
  long long int value;
  long long int counter;
};
char str[8][12];
bool visit[1 << 8][4];
struct Pair barber[1 << 8][4];
int s;
int n;
int lim;
int sum;
int cost[1 << 8];
int combine[1010][26];
int get_cost(int bitmask)
{
  int i;
  int tc;
  int f;
  int r;
  int idx = 1;
  memset(combine, 0, sizeof(combine));
  for (i = 0; i < n; i++)
  {
    if (bitmask & (1 << i))
    {
      r = 0;
      for (tc = 0; str[i][tc] != 0; tc++)
      {
        int q = str[i][tc] - 'A';
        if (!combine[r][q])
        {
          combine[r][q] = idx;
          r = idx++;
        }
        else
          r = combine[r][q];

      }

    }

  }

  return idx;
}

struct Pair spend(int bitmask, int r)
{
  if (r == sum)
  {
    struct Pair temp;
    temp.value = 0, temp.counter = 1;
    if (bitmask == lim)
      return temp;

    temp.value = -(1LL << 60), temp.counter = 0;
    return temp;
  }

  if (visit[bitmask][r])
    return barber[bitmask][r];

  struct Pair rslt;
  rslt.value = -(1LL << 60), rslt.counter = 0;
  int i;
  int tc;
  int d = 0;
  int t[8];
  for (i = 0; i < n; i++)
  {
    if (!(bitmask & (1 << i)))
      t[d++] = i;

  }

  int tlim = (1 << d) - 1;
  for (i = 1; i <= tlim; i++)
  {
    int cbitmask = 0;
    int nbitmask = bitmask;
    for (tc = 0; tc < d; tc++)
    {
      if (i & (1 << tc))
      {
        nbitmask |= 1 << t[tc];
        cbitmask |= 1 << t[tc];
      }

    }

    struct Pair q = spend(nbitmask, r + 1);
    q.value += cost[cbitmask];
    if (q.value > rslt.value)
      rslt.value = q.value, rslt.counter = q.counter;
    else
      if (q.value == rslt.value)
      rslt.counter = (rslt.counter + q.counter) % 1000000007;


  }

  visit[bitmask][r] = 1;
  return barber[bitmask][r] = rslt;
}

int Main()
{
  freopen("lol.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t = 0;
  int i;
  int tc;
  int f;
  int bitmask;
  scanf("%d", &s);
  while (s--)
  {
    scanf("%d %d", &n, &sum);
    for (i = 0; i < n; i++)
      scanf("%s", str[i]);

    lim = (1 << n) - 1;
    for (bitmask = 0; bitmask <= lim; bitmask++)
    {
      cost[bitmask] = get_cost(bitmask);
    }

    memset(visit, 0, sizeof(visit));
    struct Pair rslt = spend(0, 0);
    printf("Case #%d: %lld %lld\n", ++t, rslt.value, rslt.counter);
  }

  return 0;
}


