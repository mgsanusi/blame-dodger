#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen (const char *filename, const char *mode);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
 int
main () 
{
  FILE * fin, *fout;
  fin = new_fopen ("D-small-attempt0.in", "r");
  fout = new_fopen ("output.txt", "w");
  int T, K, C, S, i, j;
  fscanf (fin, "%d", &T);
   for (i = 1; i <= T; i++)
    {
      fscanf (fin, "%d", &K);
      fscanf (fin, "%d", &C);
      fscanf (fin, "%d", &S);
      fprintf (fout, "Case #%d: ", i);
      for (j = 1; j <= K; j++)
	fprintf (fout, "%d ", j);
      fprintf (fout, "\n");
    }
   return 0;
}

FILE * new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}
