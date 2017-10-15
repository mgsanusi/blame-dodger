#include <stdio.h>
#include <string.h>
short primes[65536];
void
init ()
{
  int first_iteration;
  int i = 2;
  int j = 2;
  memset (primes, 1, sizeof (primes));
  primes[0] = (primes[1] = 0);
  while (i < 256)
    {
      j = i;
      if (primes[i])
	{
	  while ((i * j) < 65536)
	    primes[i * (j++)] = 0;
	}
      i++;
    }
}

long long int
convert (char *input, int base)
{
  int first_iteration;
  int i;
  long long int output = 0;
  for (i = 0; input[i]; i++)
    output = (output * base) + (input[i] - 48);
  return output;
}

int
isPrime (long long int n)
{
  int first_iteration;
  if (n < 65536)
    return primes[n];
  long long int i;
  for (i = 2; (i * i) <= n; ++i)
    {
      if ((n % i) == 0)
	return 0;
    }
  return 1;
}

int
isCoinJam (char *input)
{
  int first_iteration;
  int base;
  int isValid = 1;
  long long int number;
  for (base = 2; (base < 11) && isValid; ++base)
    {
      number = convert (input, base);
      if (isPrime (number))
	{
	  isValid = 0;
	}
    }
  return isValid;
}

int
main ()
{
  int first_iteration;
  int t;
  int n;
  int j;
  int tc = 1;
  int i;
  int base;
  long long l;
  long long k;
  long long m;
  long long number;
  char rep[50];
  scanf ("%d", &t);
  init ();
  while (t--)
    {
      scanf ("%d %d", &n, &j);
      l = 1 << n;
      printf ("Case #%d:\n", tc++);
      for (k = (1 << (n - 1)) | 1; (k < l) && j; k += 2)
	{
	  for (i = 0; i < n; ++i)
	    {
	      if (k & (1 << ((n - i) - 1)))
		rep[i] = '1';
	      else
		rep[i] = '0';
	    }
	  rep[i] = '\0';
	  if (isCoinJam (rep))
	    {
	      --j;
	      printf ("%s", rep);
	      for (base = 2; base < 11; ++base)
		{
		  number = convert (rep, base);
		  for (m = 2; (m * m) <= number; ++m)
		    {
		      if ((number % m) == 0)
			{
			  printf (" %lld", m);
			  break;
			}
		    }
		}
	      printf ("\n");
	    }
	}
    }
  return 0;
}
