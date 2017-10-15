#include<stdio.h>
long long solve (void);
int
main (void)
{
  int T, i;
  scanf ("%d", &T);
  for (i = 1; i <= T; i++)
    printf ("Case #%d: %lld\n", i, solve ());
}

long long
solve (void)
{
  long long i, j, k, N, tenpow, Mten;
  long long now, next;
  int flg = 1;
  scanf ("%lld", &N);

  for (tenpow = 10; N >= tenpow; tenpow *= 10)
    {
      now = N / (tenpow / 10) % 10;
      next = N / tenpow % 10;
      if (now < next)
	{
	  flg = 0;
	  Mten = tenpow;
	}
    }
  if (flg == 1)
    return N;
  for (tenpow = 10; N >= tenpow; tenpow *= 10)
    {
      now = N / (tenpow / 10) % 10;
      next = N / tenpow % 10;
      if (tenpow <= Mten || now < next)
	{
	  k = (N / (tenpow / 10) % 10 + 1) % 10;
	  N -= tenpow / 10 * k;
	}
    }
  return N;
}
