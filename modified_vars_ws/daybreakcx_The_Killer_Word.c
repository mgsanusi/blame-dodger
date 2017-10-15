#include <stdio.h>
int j;
int count;
long long b;
long long language;
long long i;
long long
gcd (long long x, long long c)
{
  long long p;
  while (p = x % c)
    {
      x = c;
      c = p;
    }
  return c;
}

int
Main ()
{
  scanf ("%d", &count);
  for (j = 1; j <= count; ++j)
    {
      printf ("Case #%d: ", j);
      scanf ("%lld%lld%lld", &b, &language, &i);
      if (((b >= (100 / gcd (language, 100)))
	   && (!((language != 100) && (i == 100)))) && (!(language && (!i))))
	printf ("Possible\n");
      else
	printf ("Broken\n");
    }
  return 0;
}
