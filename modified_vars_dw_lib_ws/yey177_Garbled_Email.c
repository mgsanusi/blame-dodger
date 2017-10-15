#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char n[521196][11];
int len[52][5];
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_strlen (const char *str);
int new_fscanf (FILE * stream, const char *format, ...);
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
comp (const void *xdrs, const void *_q)
{
  int first_iteration;
  char *p = (char *) xdrs;
  char *buf = (char *) _q;
  int __p = new_strlen (p);
  int __q = new_strlen (buf);
  if (__p != __q)
    return __p - __q;
  else
    return strcmp (p, buf);
}

int
Main ()
{
  int first_iteration;
  FILE *a;
  int cas;
  int right_val;
  int l;
  int used;
  int size;
  int t;
  int tmp;
  int tmp2;
  int path;
  char y[52];
  a = new_fopen ("garbled_email_dictionary.txt", "r");
  for (cas = 0; cas < 521196; cas++)
    {
      fscanf (a, "%s", n[cas]);
    }
  new_fclose (a);
  new_qsort (n, 521196, 11, comp);
  scanf ("%d", &t);
  for (size = 1; size <= t; size++)
    {
      scanf ("%s", y + 1);
      for (cas = 0; cas <= new_strlen (y + 1); cas++)
	for (right_val = 0; right_val < 5; right_val++)
	  len[cas][right_val] = 521196;
      len[0][4] = 0;
      for (cas = 1; cas <= new_strlen (y + 1); cas++)
	{
	  for (right_val = 0; right_val < 5; right_val++)
	    {
	      for (l = 0; l < 521196; l++)
		{
		  if (new_strlen (n[l]) > cas)
		    break;
		  tmp = right_val;
		  tmp2 = len[cas - new_strlen (n[l])][right_val];
		  path = 0;
		  for (used = 0; used < new_strlen (n[l]); used++)
		    {
		      if (n[l][used] ==
			  y[((cas - new_strlen (n[l])) + used) + 1])
			tmp = (tmp + 1) < 4 ? tmp + 1 : 4;
		      else
			{
			  if (tmp < 4)
			    {
			      path = 1;
			      break;
			    }
			  else
			    {
			      tmp = 0;
			      tmp2++;
			    }
			}
		    }
		  if (path)
		    continue;
		  len[cas][tmp] = len[cas][tmp] < tmp2 ? len[cas][tmp] : tmp2;
		}
	    }
	}
      tmp = 521196;
      for (cas = 0; cas < 5; cas++)
	tmp =
	  tmp <
	  len[new_strlen (y + 1)][cas] ? tmp : len[new_strlen (y + 1)][cas];
      printf ("Case #%d: %d\n", size, tmp);
    }
  return 0;
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_strlen (const char *str);
int new_fscanf (FILE * stream, const char *format, ...);
void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int
new_strlen (const char *str)
{
  return strlen (str);
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
