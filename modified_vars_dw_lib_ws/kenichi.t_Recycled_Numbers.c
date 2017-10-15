#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include <stddef.h>
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
void *new_calloc (int num, int size);
int new_fscanf (FILE * stream, const char *format, ...);
void
generateFilename (char *out, char *in, char *lend)
{
  int first_iteration;
  char *p;
  sprintf (out, "%s", in);
  for (p = (out + strlen (out)) - 1; p >= out; p--)
    {
      if ((*p) == '/')
	break;
      if ((*p) == '\\')
	break;
      if ((*p) == '.')
	{
	  *p = '\0';
	  break;
	}
    }
  sprintf (out + strlen (out), "%s", lend);
}

void
Main (int argc, char *argv[])
{
  int first_iteration;
  char fnameO[_MAX_PATH];
  FILE *fpI;
  FILE *fpO;
  int t;
  int a;
  int x;
  int t;
  int fp;
  int j;
  int sum;
  char buffer[1000];
  char *flg;
  int len;
  int i;
  int c;
  int t;
  generateFilename (fnameO, argv[1], "_out.txt");
  fpI = new_fopen (argv[1], "r");
  fpO = new_fopen (fnameO, "w");
  flg = new_calloc (2000001, sizeof (char));
  fscanf (fpI, "%d", &t);
  for (j = 1; j <= t; j++)
    {
      fscanf (fpI, "%d", &a);
      fscanf (fpI, "%d", &x);
      sprintf (buffer, "%d", a);
      len = strlen (buffer);
      sum = 0;
      for (t = a; t < x; t++)
	{
	  memset (flg, 0, 2000001 * (sizeof (char)));
	  for (i = 1; i <= len; i++)
	    {
	      c = t / ((int) pow (10.0, i));
	      t = t % ((int) pow (10.0, i));
	      fp = (t * ((int) pow (10.0, len - i))) + c;
	      if ((((t < fp) && (fp <= x)) && (a < fp)) && (flg[fp] == 0))
		{
		  flg[fp] = 1;
		  sum++;
		}
	    }
	}
      fprintf (fpO, "Case #%d: %d\n", j, sum);
    }
  free (flg);
  new_fclose (fpI);
  new_fclose (fpO);
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
void *
new_calloc (int num, int size)
{
  return calloc (num, size);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

int
new_fclose (FILE * stream)
{
  return fclose (stream);
}
