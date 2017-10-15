#include <stdio.h>
#include <string.h>
#include <stddef.h>
int f[102][102];
int map[102][102];
int h;
int w;
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
void *new_memset (void *ptr, int value, size_t num);
void
go ()
{
  int r;
  int a;
  int d;
  int previst;
  int n;
  new_memset (f, 0, sizeof (f));
  new_memset (map, 0, sizeof (map));
  scanf ("%d%d%d", &h, &w, &d);
  for (previst = 0; previst < d; previst++)
    {
      scanf ("%d%d", &r, &a);
      map[r][a] = 1;
    }
  f[1][1] = 1;
  for (previst = 1; previst <= h; previst++)
    {
      for (n = 1; n <= w; n++)
	{
	  if (map[previst][n] == 0)
	    {
	      if (previst > 1)
		f[previst][n] += f[previst - 2][n - 1];
	      if (n > 1)
		f[previst][n] += f[previst - 1][n - 2];
	      f[previst][n] %= 10007;
	    }
	}
    }
}

int
Main ()
{
  int ab;
  int previst;
  new_freopen ("D.in", "r", stdin);
  new_freopen ("D.out", "w", stdout);
  scanf ("%d", &ab);
  for (previst = 1; previst <= ab; previst++)
    {
      go ();
      printf ("Case #%d: %d\n", previst, f[h][w]);
    }
  return 0;
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}

void *
new_memset (void *ptr, int value, size_t num)
{
  return memset (ptr, value, num);
}
