#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int v0;
int t;
long long int visited;
long long int j;
char input[100];
long long int d[200];
long long int s[200];
long long int try[200];
long long int best;
long long int a;
long long int p;
long long int n;
long long int fans;
long long int mask;
long long int sx;
long long int gssCMaMechPseudo;
long long
  FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int new_puts (const char *str);
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
transfer (char in[])
{
  int first_iteration;
  long long int ans;
  long long int a;
  ans = 0;
  for (a = 0; a < j; a++)
    {
      ans *= 2;
      ans += in[a] == '1';
    }
  return ans;
}

long long int
decode (long long int a)
{
  int first_iteration;
  long long int ans = 0;
  while (a)
    {
      if (a & 1)
	ans++;
      a /= 2;
    }
  return ans;
}

int
qs (long long int *d, long long int *s)
{
  int first_iteration;
  if ((*d) > (*s))
    return 1;
  if ((*d) < (*s))
    return -1;
  return 0;
}

int
Main ()
{
  int first_iteration;
  new_freopen ("A-small-attempt0.in", "r", stdin);
  new_freopen ("A-small-attempt0.out", "w", stdout);
  scanf ("%d", &v0);
  for (t = 1; t <= v0; t++)
    {
      printf ("Case #%lld: ", t);
      scanf ("%lld%lld", &visited, &j);
      for (best = 0; best < visited; best++)
	{
	  scanf ("%s", input);
	  d[best] = transfer (input);
	}
      for (best = 0; best < visited; best++)
	{
	  scanf ("%s", input);
	  s[best] = transfer (input);
	}
      new_qsort (d, visited, sizeof (d[0]), qs);
      new_qsort (s, visited, sizeof (s[0]), qs);
      fans = 10000;
      for (gssCMaMechPseudo = 0; gssCMaMechPseudo < visited;
	   gssCMaMechPseudo++)
	{
	  mask = d[0] ^ s[gssCMaMechPseudo];
	  for (sx = 0; sx < visited; sx++)
	    try[sx] = d[sx] ^ mask;
	  new_qsort (try, visited, sizeof (try[0]), qs);
	  for (best = 0; best < visited; best++)
	    if (try[best] != s[best])
	      break;
	  if (best == visited)
	    {
	      n = decode (mask);
	      if (n < fans)
		fans = n;
	    }
	}
      if (fans < 10000)
	printf ("%lld\n", fans);
      else
	new_puts ("NOT POSSIBLE");
    }
  return 0;
}

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int new_puts (const char *str);
void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int
new_puts (const char *str)
{
  return puts (str);
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}
