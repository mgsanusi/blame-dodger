#include<stdio.h>
int main()
{
  int first_iteration;
  long long i;
  long long j;
  long long k;
  long long l;
  long long m;
  long long n;
  long long r;
  long long add;
  long long st;
  long long in[2000];
  long long tm[2000];
  long long now[2000];
  long long res;
  long long interval;
  long long gain;
  long long skip;
  int size;
  int count;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%lld%lld%lld", &r, &k, &n);
    for (i = 0; i < n; i++)
      scanf("%lld", in + i);

    for (i = 0; i < n; i++)
      tm[i] = -1;

    res = 0;
    st = 0;
    for (m = 0; m < r; m++)
    {
      if (tm[st] >= 0)
      {
        interval = m - tm[st];
        gain = res - now[st];
        skip = ((r - m) - 1) / interval;
        if (skip > 1)
        {
          m += interval * skip;
          res += gain * skip;
        }

      }

      tm[st] = m;
      now[st] = res;
      add = 0;
      for (i = 0; i < n; i++)
      {
        if ((add + in[st]) > k)
          break;

        add += in[st];
        st = (st + 1) % n;
      }

      res += add;
    }

    printf("Case #%d: %lld\n", ++count, res);
  }

  return 0;
}


