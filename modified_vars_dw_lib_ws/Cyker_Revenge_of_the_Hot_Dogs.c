#include "stdio.h"
#include "string.h"
#include <stddef.h>
char game[102][102];
int win[102];
int count[102];
double good[102];
double owp[102];
double oowp[102];
FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, int num);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int
Main (int argc, char **argv)
{
  int first_iteration;
  int r;
  int n;
  int n;
  int pos;
  int tt;
  FILE *b;
  b = new_fopen (argv[1], "r");
  fscanf (b, "%d", &r);
  for (n = 1; n <= r; n++)
    {
      new_memset (game, 0, sizeof (game));
      new_memset (win, 0, sizeof (win));
      new_memset (count, 0, sizeof (count));
      new_memset (good, 0, sizeof (good));
      new_memset (owp, 0, sizeof (owp));
      new_memset (oowp, 0, sizeof (oowp));
      fscanf (b, "%d ", &n);
      char out;
      for (pos = 0; pos < n; pos++)
	{
	  for (tt = 0; tt < n; tt++)
	    {
	      fscanf (b, "%c", &game[pos][tt]);
	    }
	  fscanf (b, "%c", &out);
	}
      for (pos = 0; pos < n; pos++)
	{
	  for (tt = 0; tt < n; tt++)
	    {
	      if (game[pos][tt] == '1')
		{
		  win[pos]++;
		  count[pos]++;
		}
	      else if (game[pos][tt] == '0')
		{
		  count[pos]++;
		}
	    }
	}
      for (pos = 0; pos < n; pos++)
	{
	  good[pos] = ((double) win[pos]) / count[pos];
	}
      for (pos = 0; pos < n; pos++)
	{
	  for (tt = 0; tt < n; tt++)
	    {
	      if (game[pos][tt] == '1')
		{
		  owp[pos] += ((double) win[tt]) / (count[tt] - 1);
		}
	      else if (game[pos][tt] == '0')
		{
		  owp[pos] += ((double) (win[tt] - 1)) / (count[tt] - 1);
		}
	    }
	  owp[pos] /= count[pos];
	}
      for (pos = 0; pos < n; pos++)
	{
	  for (tt = 0; tt < n; tt++)
	    {
	      if (game[pos][tt] != '.')
		{
		  oowp[pos] += owp[tt];
		}
	    }
	  oowp[pos] /= count[pos];
	}
      printf ("Case #%d:\n", n);
      for (pos = 0; pos < n; pos++)
	{
	  printf ("%lf\n",
		  ((0.25 * good[pos]) + (0.50 * owp[pos])) +
		  (0.25 * oowp[pos]));
	}
    }
  new_fclose (b);
  return 0;
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

void *new_memset (void *ptr, int value, int num);
int
new_fclose (FILE * stream)
{
  return fclose (stream);
}

void *
new_memset (void *ptr, int value, int num)
{
  return memset (ptr, value, num);
}
