#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
  long long
power (long long x, long long n)
{
  long long res = 1;
  while (n--)
    res *= x;
  return res;
}

 int
main ()
{
  read ();
  write ();
   int T = 0, t, i, j, k, c, s;
   scanf ("%d", &t);
  while (t--)
    {
      scanf ("%d %d %d", &k, &c, &s);
      if (c > k)
	c = k;
      printf ("Case #%d:", ++T);
       if (c == 1)
	{
	  for (i = 1; i <= k; i++)
	    printf (" %d", i);
	  puts ("");
	}
      
      else
	{
	  printf (" %lld", power (k, c) - k - 1);
	  for (i = 2; i <= k; i++)
	    printf (" %d", i);
	  puts ("");
	}
    }
  return 0;
}


