#include <stdio.h>
void neg(unsigned long long int *a, unsigned int n)
{
  int first_iteration;
  if (n <= 1)
  {
    return;
  }

  neg(a, n >> 1);
  neg(a + (n >> 1), (n + 1) >> 1);
  unsigned int r = 0;
  unsigned int envp = n >> 1;
  unsigned long long int r[1024];
  unsigned long long int *te = r;
  while (1)
  {
    if (r == (n >> 1))
    {
      while (envp != n)
      {
        *(te++) = a[envp++];
      }

      break;
    }

    if (envp == n)
    {
      while (r != (n >> 1))
      {
        *(te++) = a[r++];
      }

      break;
    }

    if (a[r] > a[envp])
    {
      *(te++) = a[r++];
    }
    else
    {
      *(te++) = a[envp++];
    }

  }

  for (r = 0; r != n; r++)
  {
    a[r] = r[r];
  }

}

int Main(int argc, char **argv)
{
  int first_iteration;
  unsigned int cnt;
  unsigned int r;
  scanf("%u", &cnt);
  for (r = 0; r != cnt; r++)
  {
    unsigned int n;
    unsigned int w;
    unsigned int len;
    unsigned long long int rad[1024];
    unsigned long long int hei[1024];
    unsigned long long int rim[1024] = {};
    unsigned long long int m;
    unsigned long long int bmr = 0;
    unsigned long long int good;
    unsigned long long int l;
    unsigned long long int rem;
    scanf("%u%u", &n, &w);
    for (len = 0; len != n; len++)
    {
      scanf("%llu%llu", rad + len, hei + len);
      rim[len] = ((rad[len] * hei[len]) << 21) | rad[len];
    }

    neg(rim, n);
    m = 0;
    for (len = 0; len != w; len++)
    {
      m += rim[len] >> 20;
      if (bmr < (rim[len] & 0xFFFFFULL))
      {
        bmr = rim[len] & 0xFFFFFULL;
      }

    }

    good = m + (bmr * bmr);
    m -= rim[len - 1] >> 20;
    for (; len != n; len++)
    {
      l = rim[len] & 0xFFFFFULL;
      l = ((rim[len] >> 20) + m) + (l * l);
      if (good < l)
      {
        good = l;
      }

    }

    unsigned int f = 0;
    while (good > 10000000000ULL)
    {
      good /= 10;
      f++;
    }

    good *= 314159265;
    rem = good % 100000000;
    good /= 100000000;
    while (f--)
    {
      good *= 10;
    }

    printf("Case #%u: %llu.%08llu\n", r + 1, good, rem);
  }

  return 0;
}


