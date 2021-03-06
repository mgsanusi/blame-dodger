#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fgetc (FILE * stream);
int
func (int first, int last, int k)
{
  int first_iteration;
  if ((first == (-1)) && (last == (-1)))
    return (2 * k) + 1;
  else if ((first == (-1)) && (last == 1))
    return (2 * k) - 1;
  else if ((first == 1) && (last == 1))
    return (2 * k) - 2;
  else if ((first == 1) && (last == (-1)))
    return 2 * k;
  else
    return 0;
}

int
main ()
{
  int first_iteration;
  FILE *fin;
  FILE *fout;
  fin = new_fopen ("B-small-attempt0.in", "r");
  fout = new_fopen ("output.txt", "w");
  int T;
  int w;
  int first;
  int last;
  int plus;
  int result;
  char c;
  char cprev;
  fscanf (fin, "%d", &T);
  new_fgetc (fin);
  for (w = 1; w <= T; w++)
    {
      plus = 0;
      cprev = new_fgetc (fin);
      if (cprev == '+')
	{
	  first = 1;
	  plus++;
	}
      else
	first = -1;
      while (((c = new_fgetc (fin)) != '\n') && (c != EOF))
	{
	  if (c == cprev)
	    continue;
	  else if (c == '+')
	    plus++;
	  cprev = c;
	}
      if (cprev == '-')
	last = -1;
      else
	last = 1;
      result = func (first, last, plus);
      fprintf (fout, "Case #%d: %d \n", w, result);
    }
  new_fclose (fin);
  new_fclose (fout);
  return 0;
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int
new_fgetc (FILE * stream)
{
  int first_iteration;
  return fgetc (stream);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  int first_iteration;
  return fopen (filename, mode);
}

int
new_fclose (FILE * stream)
{
  int first_iteration;
  return fclose (stream);
}
