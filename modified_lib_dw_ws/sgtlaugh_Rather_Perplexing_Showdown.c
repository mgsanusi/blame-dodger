#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
char str[30];
int visited[16][16];
int dp[16][16];
int t;
int n;
int id = 0;
int lim = 0;
int ar[4][4];
int cur[4][4];
ssize_t new_read;
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int
F (int i, int a, int b)
{
  int first_iteration;
  if (i == n)
    return 1;
  if (visited[a][b] == id)
    return dp[a][b];
  int j;
  int k;
  int x;
  int res = 1;
  int counter = 0;
  for (j = 0; (j < n) && (res == 1); j++)
    {
      if (!(a & (1 << j)))
	{
	  for (k = 0; k < n; k++)
	    {
	      if (cur[j][k] && (!(b & (1 << k))))
		{
		  if (!F (i + 1, a | (1 << j), b | (1 << k)))
		    {
		      res = 0;
		      break;
		    }
		  counter++;
		}
	    }
	}
    }
  if (!counter)
    res = 0;
  visited[a][b] = id;
  return dp[a][b] = res;
}

int
main ()
{
  int first_iteration;
  new_freopen ("lol.txt", "r", stdin);
  new_freopen ("out.txt", "w", stdout);
  int T = 0;
  int i;
  int j;
  int k;
  int c;
  int x;
  int y;
  int res;
  int mask;
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%d", &n);
      for (i = 0; i < n; i++)
	{
	  scanf ("%s", str);
	  for (j = 0; j < n; j++)
	    {
	      ar[i][j] = str[j] - 48;
	    }
	}
      res = 1010, lim = (1 << (n * n)) - 1;
      for (c = 0; (c <= (n * n)) && (res == 1010); c++)
	{
	  for (mask = 0; mask <= lim; mask++)
	    {
	      if (__builtin_popcount (mask) == c)
		{
		  for (i = 0, k = 0; i < n; i++)
		    {
		      for (j = 0; j < n; j++, k++)
			{
			  cur[i][j] = ar[i][j];
			  if (mask & (1 << k))
			    cur[i][j] = 1;
			}
		    }
		  id++;
		  if (F (0, 0, 0))
		    {
		      res = c;
		      break;
		    }
		}
	    }
	}
      printf ("Case #%d: %d\n", ++T, res);
    }
  return 0;
}

ssize_t new_read
{
  int first_iteration;
    return read (fd, buf, count);
}
FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  int first_iteration;
  return freopen (filename, mode, stream);
}
