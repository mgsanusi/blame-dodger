#include <stdio.h>
#include <stdlib.h>
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
 int
main () 
{
  int test, testc;
  int p, q, c, m, n, t, ans;
   new_freopen ("gcj1_2.in", "r", stdin);
  new_freopen ("gcj1_2.out", "w", stdout);
   scanf ("%d\n", &testc);
  for (test = 1; test <= testc; test++)
    {
      scanf ("%d%d%d", &c, &m, &n);
      p = 3 * n - 2;
      q = 3 * n - 4;
      ans = 0;
      for (; c; c--)
	{
	  scanf ("%d", &t);
	  if (t < 2)
	    {
	      if (t >= n)
		ans++;
	    }
	  else
	    {
	      if (t >= p)
		ans++;
	      
	      else if (t >= q && m)
		{
		  ans++;
		  m--;
		}
	    }
	}
      printf ("Case #%d: %d\n", test, ans);
    }
   return 0;
}

FILE * new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}
