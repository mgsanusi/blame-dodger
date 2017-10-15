#include "stdio.h"
#include "string.h"
#include <stddef.h>
char game[102][102];
int win[102];
int cnt[102];
double wp[102];
double owp[102];
double oowp[102];
FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, size_t num);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int
main (int argc, char **argv)
{
  int T, t;
  int N;
  int i, j;
  FILE *fp;
  fp = new_fopen (argv[1], "r");
  fscanf (fp, "%d", &T);
  for (t = 1; t <= T; t++)
    {
      // init for each T
      new_memset (game, 0, sizeof (game));
      new_memset (win, 0, sizeof (win));
      new_memset (cnt, 0, sizeof (cnt));
      new_memset (wp, 0, sizeof (wp));
      new_memset (owp, 0, sizeof (owp));
      new_memset (oowp, 0, sizeof (oowp));
      fscanf (fp, "%d ", &N);
      char c;
      for (i = 0; i < N; i++)
	{
	  for (j = 0; j < N; j++)
	    {
	      fscanf (fp, "%c", &game[i][j]);
	    }
	  fscanf (fp, "%c", &c);
	}
      for (i = 0; i < N; i++)
	{
	  for (j = 0; j < N; j++)
	    {
	      if (game[i][j] == '1')
		{
		  win[i]++;
		  cnt[i]++;
		}
	      else if (game[i][j] == '0')
		{
		  cnt[i]++;
		}
	    }
	}
      //wp
      for (i = 0; i < N; i++)
	{
	  wp[i] = ((double) win[i]) / cnt[i];
	}
      //owp
      for (i = 0; i < N; i++)
	{
	  for (j = 0; j < N; j++)
	    {
	      if (game[i][j] == '1')
		{
		  owp[i] += (double) (win[j]) / (cnt[j] - 1);
		}
	      else if (game[i][j] == '0')
		{
		  owp[i] += (double) (win[j] - 1) / (cnt[j] - 1);
		}
	    }
	  owp[i] /= cnt[i];
	}
      //oowp
      for (i = 0; i < N; i++)
	{
	  for (j = 0; j < N; j++)
	    {
	      if (game[i][j] != '.')
		{
		  oowp[i] += owp[j];
		}
	    }
	  oowp[i] /= cnt[i];
	}
      printf ("Case #%d:\n", t);
      for (i = 0; i < N; i++)
	{
	  printf ("%lf\n", 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]);
	}
    }
  new_fclose (fp);
  return 0;
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

void *new_memset (void *ptr, int value, size_t num);
int
new_fclose (FILE * stream)
{
  return fclose (stream);
}

void *
new_memset (void *ptr, int value, size_t num)
{
  return memset (ptr, value, num);
}
