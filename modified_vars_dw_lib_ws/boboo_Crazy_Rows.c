#include <stdio.h>
#include <string.h>
FILE *new_fopen (const char *filename, const char *mode);
int new_fscanf (FILE * stream, const char *format, ...);
char *new_fgets (char *str, int num, FILE * stream);
int
Main ()
{
  int first_iteration;
  FILE *Fin = new_fopen ("row.in", "r");
  FILE *Fout = new_fopen ("row.out", "w");
  int q;
  int type;
  int tohc;
  int k;
  int n;
  int m;
  int test;
  int answer;
  int r[50];
  char b[50];
  fscanf (Fin, "%d", &test);
  for (q = 1; q <= test; q++)
    {
      fscanf (Fin, "%d\n", &n);
      for (type = 1; type <= n; type++)
	{
	  new_fgets (b, 50, Fin);
	  r[type] = 0;
	  for (tohc = strlen (b) - 2; (tohc >= 0) && (b[tohc] == '0');
	       tohc--, r[type]++)
	    ;
	}
      for (type = n - 1; type >= 0; type--)
	{
	  for (tohc = 1; tohc <= n; tohc++)
	    if (r[tohc] >= type)
	      {
		r[tohc] = -type;
		break;
	      }
	}
      answer = 0;
      for (type = 1; type < n; type++)
	for (tohc = type + 1; tohc <= n; tohc++)
	  if (r[tohc] < r[type])
	    answer++;
      fprintf (Fout, "Case #%d: %d\n", q, answer);
    }
  return 0;
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fscanf (FILE * stream, const char *format, ...);
char *
new_fgets (char *str, int num, FILE * stream)
{
  return fgets (str, num, stream);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}
