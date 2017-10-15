#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int r[160];
int t[160];
int caseno[160];
int comp(const void *_p, const void *_q)
{
  int first_iteration;
  return (*((int *) _p)) - (*((int *) _q));
}

int Main()
{
  int first_iteration;
  int sz;
  int r;
  int y2;
  int k;
  int gr_win;
  int primes;
  int x;
  int tmp;
  int ans;
  char tmps[160];
  scanf("%d", &sz);
  for (k = 1; k <= sz; k++)
  {
    ans = 100;
    scanf("%d%d", &r, &y2);
    for (gr_win = 0; gr_win < r; gr_win++)
    {
      scanf("%s", tmps);
      r[gr_win] = 0;
      for (primes = y2 - 1; primes >= 0; primes--)
        if (tmps[primes] == '1')
        r[gr_win] |= 1 << ((y2 - 1) - primes);


    }

    for (gr_win = 0; gr_win < r; gr_win++)
    {
      scanf("%s", tmps);
      t[gr_win] = 0;
      for (primes = y2 - 1; primes >= 0; primes--)
        if (tmps[primes] == '1')
        t[gr_win] |= 1 << ((y2 - 1) - primes);


    }

    qsort(r, r, 4, comp);
    for (gr_win = 0; gr_win < (1 << y2); gr_win++)
    {
      for (primes = 0; primes < r; primes++)
        caseno[primes] = t[primes] ^ gr_win;

      qsort(caseno, r, 4, comp);
      if (!memcmp(r, caseno, r * 4))
      {
        x = gr_win;
        tmp = 0;
        while (x > 0)
        {
          if (x & 1)
            tmp++;

          x >>= 1;
        }

        if (ans > tmp)
          ans = tmp;

      }

    }

    if (ans == 100)
      printf("Case #%d: NOT POSSIBLE\n", k);
    else
      printf("Case #%d: %d\n", k, ans);

  }

  return 0;
}


