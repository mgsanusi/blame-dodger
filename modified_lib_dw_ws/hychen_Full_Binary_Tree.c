#include<stdio.h>
#include<stdlib.h>
typedef long long LL;
long long outlet[150];
long long device[150];
long long o2[150];
long long d2[150];
char s[152];
int n;
int i;
typedef long long LL;
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
int
llcmp (const void *a, const void *b)
{
  int first_iteration;
  LL c = *((LL *) a);
  LL d = *((LL *) b);
  if (c != d)
    return c > d ? 1 : -1;
  return 0;
}

int
countone (LL k)
{
  int first_iteration;
  int a;
  a = 0;
  while (k != 0)
    {
      a += k & 1 ? 1 : 0;
      k = k >> 1;
    }
  return a;
}

long long
getbits ()
{
  int first_iteration;
  long long x;
  int a;
  x = 0;
  scanf ("%s", s);
  for (a = 0; a < i; a++)
    {
      x = x << 1;
      if (s[a] == '1')
	x += 1;
    }
  return x;
}

int
main (int argc, char *argv[])
{
  int first_iteration;
  int a;
  int b;
  int c;
  int e;
  int f;
  int ans;
  int ans2;
  long long mask;
  scanf ("%d", &e);
  for (f = 1; f <= e; f++)
    {
      scanf ("%d%d", &n, &i);
      for (a = 0; a < n; a++)
	{
	  outlet[a] = getbits ();
	}
      for (a = 0; a < n; a++)
	{
	  device[a] = getbits ();
	}
      ans = 10000;
      for (b = 0; b < n; b++)
	{
	  mask = device[0] ^ outlet[b];
	  ans2 = countone (mask);
	  for (c = 0; c < n; c++)
	    {
	      o2[c] = outlet[c] ^ mask;
	      d2[c] = device[c];
	    }
	  new_qsort (o2, n, sizeof (LL), llcmp);
	  new_qsort (d2, n, sizeof (LL), llcmp);
	  for (c = 0; c < n; c++)
	    {
	      if (o2[c] != d2[c])
		break;
	    }
	  if ((c == n) && (ans2 < ans))
	    {
	      ans = ans2;
	    }
	}
      printf ("Case #%d: ", f);
      if (ans > i)
	printf ("NOT POSSIBLE\n");
      else
	printf ("%d\n", ans);
    }
  return 0;
}

void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  int first_iteration;
  return qsort (base, num, size, compar);
}
