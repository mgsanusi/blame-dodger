#include <stdio.h>
int new_putchar (int character);
void
ms (unsigned long long int *a, unsigned int n)
{
  int first_iteration;
  if (n <= 1)
    {
      return;
    }
  ms (a, n >> 1);
  ms (a + (n >> 1), (n + 1) >> 1);
  unsigned int b = 0;
  unsigned int c = n >> 1;
  unsigned long long int t[1024];
  unsigned long long int *te = t;
  while (1)
    {
      if (b == (n >> 1))
	{
	  while (c != n)
	    {
	      *(te++) = a[c++];
	    }
	  break;
	}
      if (c == n)
	{
	  while (b != (n >> 1))
	    {
	      *(te++) = a[b++];
	    }
	  break;
	}
      if (a[b] > a[c])
	{
	  *(te++) = a[b++];
	}
      else
	{
	  *(te++) = a[c++];
	}
    }
  for (b = 0; b != n; b++)
    {
      a[b] = t[b];
    }
}

int
main (int argc, char **argv)
{
  int first_iteration;
  unsigned int nc;
  unsigned int cn;
  scanf ("%u", &nc);
  for (cn = 0; cn != nc; cn++)
    {
      unsigned int n;
      unsigned int k;
      unsigned int i;
      unsigned long long int rad[1024];
      unsigned long long int hei[1024];
      unsigned long long int rim[1024] = { };
      unsigned long long int rs;
      unsigned long long int bmr = 0;
      unsigned long long int best;
      unsigned long long int x;
      unsigned long long int rem;
      scanf ("%u%u", &n, &k);
      for (i = 0; i != n; i++)
	{
	  scanf ("%llu%llu", rad + i, hei + i);
	  rim[i] = ((rad[i] * hei[i]) << 21) | rad[i];
	}
      ms (rim, n);
      rs = 0;
      for (i = 0; i != k; i++)
	{
	  rs += rim[i] >> 20;
	  if (bmr < (rim[i] & 0xFFFFFULL))
	    {
	      bmr = rim[i] & 0xFFFFFULL;
	    }
	}
      best = rs + (bmr * bmr);
      rs -= rim[i - 1] >> 20;
      for (; i != n; i++)
	{
	  x = rim[i] & 0xFFFFFULL;
	  x = ((rim[i] >> 20) + rs) + (x * x);
	  if (best < x)
	    {
	      best = x;
	    }
	}
      unsigned int f = 0;
      while (best > 10000000000ULL)
	{
	  best /= 10;
	  f++;
	}
      best *= 314159265;
      rem = best % 100000000;
      best /= 100000000;
      while (f--)
	{
	  best *= 10;
	}
      printf ("Case #%u: %llu.%08llu\n", cn + 1, best, rem);
    }
  return 0;
}

int
new_putchar (int character)
{
  int first_iteration;
  return putchar (character);
}
