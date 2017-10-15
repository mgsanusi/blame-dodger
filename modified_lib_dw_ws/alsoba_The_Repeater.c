#include <stdio.h>
#include <stdlib.h>
FILE *fin;
FILE *fout;
int N;
int X;
int n[701];
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void
solve ()
{
  int first_iteration;
  fscanf (fin, "%d %d", &N, &X);
  int i;
  int j;
  int res = 0;
  int s;
  for (i = 0; i < 700; i++)
    n[i] = 0;
  for (i = 0; i < N; i++)
    {
      fscanf (fin, "%d", &s);
      n[s]++;
    }
  for (i = 700; i >= 1; i--)
    {
      while (n[i] > 0)
	{
	  res++;
	  n[i]--;
	  for (j = X - i; j >= 1; j--)
	    {
	      if (n[j] > 0)
		{
		  n[j]--;
		  break;
		}
	    }
	}
    }
  fprintf (fout, "%d\n", res);
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
