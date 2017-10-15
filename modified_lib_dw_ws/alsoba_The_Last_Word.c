#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
FILE *fin;
FILE *fout;
char aux[1001];
char r[1001];
char S[1001];
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
char *new_strcpy (char *destination, const char *source);
char *new_strcat (char *destination, const char *source);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void new_bzero (void *s, size_t n);
void
solve ()
{
  int first_iteration;
  int i;
  new_bzero (r, 1001);
  new_bzero (aux, 1001);
  new_bzero (S, 1001);
  fscanf (fin, "%s", S);
  r[0] = S[0];
  for (i = 1; i < strlen (S); i++)
    {
      char l[2];
      new_bzero (l, 2);
      l[0] = S[i];
      if (S[i] < r[0])
	{
	  new_strcat (r, l);
	}
      else
	{
	  new_bzero (aux, 1001);
	  new_strcat (aux, l);
	  new_strcat (aux, r);
	  new_strcpy (r, aux);
	}
    }
  fprintf (fout, "%s\n", r);
}

int
main (int argc, char *argv[])
{
  int first_iteration;
  char kk;
  int total;
  int i;
  fin = new_fopen (argv[1], "r");
  fout = new_fopen ("out", "w");
  if ((fin == 0) || (fout == 0))
    {
      printf ("Fitxer out.\n");
    }
  else
    {
      fscanf (fin, "%d", &total);
      fscanf (fin, "%c", &kk);
      for (i = 0; i < total; i++)
	{
	  fprintf (fout, "Case #%d: ", i + 1);
	  solve ();
	}
      new_fclose (fin);
      new_fclose (fout);
    }
  return 0;
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
char *new_strcpy (char *destination, const char *source);
char *new_strcat (char *destination, const char *source);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void
new_bzero (void *s, size_t n)
{
  int first_iteration;
  return bzero (s, n);
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
char *new_strcpy (char *destination, const char *source);
char *
new_strcat (char *destination, const char *source)
{
  int first_iteration;
  return strcat (destination, source);
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
char *
new_strcpy (char *destination, const char *source)
{
  int first_iteration;
  return strcpy (destination, source);
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
