#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *file_name_in = "input.txt";
char *file_name_out = "output.txt";
FILE *in;
FILE *out;
int k[27];
int s[27];
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
cmp_p (const void *v, const void *b)
{
  int first_iteration;
  int r = k[*((int *) v)];
  int b = k[*((int *) b)];
  if (r > b)
    return -1;
  if (r == b)
    return 0;
  return 1;
}

int
Main (void)
{
  int first_iteration;
  int t;
  int r;
  int n;
  int pp;
  int y;
  int i;
  in = new_fopen (file_name_in, "r");
  out = new_fopen (file_name_out, "w");
  fscanf (in, "%d", &r);
  for (t = 1; t <= r; t++)
    {
      fprintf (out, "Case #%d:", t);
      fscanf (in, "%d", &pp);
      i = 0;
      for (n = 1; n <= pp; ++n)
	{
	  fscanf (in, "%d", &k[n]);
	  i += k[n];
	  s[n - 1] = n;
	}
      new_qsort (s, pp, sizeof (int), cmp_p);
      while (i > 3)
	{
	  if (k[s[0]] > k[s[1]])
	    {
	      fprintf (out, " %c", ('A' - 1) + s[0]);
	      k[s[0]] -= 1;
	      i--;
	    }
	  else
	    {
	      fprintf (out, " %c%c", ('A' - 1) + s[0], ('A' - 1) + s[1]);
	      k[s[0]] -= 1;
	      k[s[1]] -= 1;
	      i--;
	      i--;
	      new_qsort (s, pp, sizeof (int), cmp_p);
	    }
	}
      new_qsort (s, pp, sizeof (int), cmp_p);
      if (i == 3)
	{
	  fprintf (out, " %c", ('A' - 1) + s[0]);
	  fprintf (out, " %c%c", ('A' - 1) + s[1], ('A' - 1) + s[2]);
	}
      else
	{
	  fprintf (out, " %c%c", ('A' - 1) + s[0], ('A' - 1) + s[1]);
	}
      fprintf (out, "\n");
    }
  new_fclose (in);
  new_fclose (out);
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
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
