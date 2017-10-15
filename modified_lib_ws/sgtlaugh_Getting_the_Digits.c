#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("out.txt", "w", stdout)
  bool visited[1 << 17];
int t, n, lim, dp[1 << 17];
char first[1010][25], second[1010][25];
ssize_t new_read (int fd, void *buf, size_t count);
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
 int
F (int mask)
{
  if (mask == lim)
    return 0;
  if (visited[mask])
    return dp[mask];
   int i, j, x, y, z, res = 0;
  for (i = 0; i < n; i++)
    {
      if (!(mask & (1 << i)))
	{
	  x = 0, y = 0;
	  for (j = 0; j < n; j++)
	    {
	      if (mask & (1 << j))
		{
		  if (strcmp (first[i], first[j]) == 0)
		    x++;
		  if (strcmp (second[i], second[j]) == 0)
		    y++;
		}
	    }
	  z = F (mask | (1 << i)) + ((x > 0) && (y > 0));
	  if (z > res)
	    res = z;
	}
    }
   visited[mask] = true;
  return (dp[mask] = res);
}

 int
main ()
{
  new_read ();
  write ();
  int T = 0, i, j, k, x, res;
   scanf ("%d", &t);
  while (t--)
    {
      scanf ("%d", &n);
      for (i = 0; i < n; i++)
	scanf ("%s %s", first[i], second[i]);
       clr (visited);
      lim = (1 << n) - 1;
      printf ("Case #%d: %d\n", ++T, F (0));
    }
  return 0;
}

ssize_t new_read (int fd, void *buf, size_t count)
{
  return read (fd, buf, count);
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}
