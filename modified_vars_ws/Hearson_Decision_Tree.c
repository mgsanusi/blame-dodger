#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
char d[65];
long long x[256];
long long base;
void
reset ()
{
  int i;
  gets (d);
  memset (x, 0, sizeof (x));
  base = 0;
  for (i = 0; i < strlen (d); i++)
    {
      if (!x[d[i]])
	{
	  x[d[i]] = -1;
	  base++;
	}
    }
  if (base <= 1)
    base = 2;
}

void
clear ()
{
  int s2;
  int i;
  unsigned long long xdrs = 0;
  unsigned long long n = 1;
  s2 = 0;
  for (i = 0; i < strlen (d); i++)
    {
      if (x[d[i]] == (-1))
	{
	  x[d[i]] = s2++;
	}
    }
  for (i = 0; i < 256; i++)
    {
      if (x[i] == 0)
	{
	  x[i] = 1;
	}
      else if (x[i] == 1)
	{
	  x[i] = 0;
	}
    }
  for (i = strlen (d) - 1; i >= 0; i--)
    {
      xdrs += n * x[d[i]];
      n *= base;
    }
  printf ("%qd\n", xdrs);
}

void
singleCase ()
{
  reset ();
  clear ();
}

int
Main ()
{
  int s2;
  int i;
  scanf ("%d\n", &s2);
  for (i = 1; i <= s2; i++)
    {
      printf ("Case #%d: ", i);
      singleCase ();
    }
  return 0;
}
