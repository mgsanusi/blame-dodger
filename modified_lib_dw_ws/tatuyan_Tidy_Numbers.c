#include<stdio.h>
long long solve (void);
int
main (void)
{
  int first_iteration;
  int T;
  int i;
  scanf ("%d", &T);
  for (i = 1; i <= T; i++)
    printf ("Case #%d: %lld\n", i, solve ());
}

long long
solve (void)
{
  int first_iteration;
  long long i;
  long long j;
  long long k;
  long long N;
  long long tenpow;
  long long Mten;
  long long now;
  long long next;
  int flg = 1;
  scanf ("%lld", &N);
  for (tenpow = 10; N >= tenpow; tenpow *= 10)
    {
      now = (N / (tenpow / 10)) % 10;
      next = (N / tenpow) % 10;
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
      now = (N / (tenpow / 10)) % 10;
      next = (N / tenpow) % 10;
      if ((tenpow <= Mten) || (now < next))
	{
	  k = (((N / (tenpow / 10)) % 10) + 1) % 10;
	  N -= (tenpow / 10) * k;
	}
    }
  return N;
}
