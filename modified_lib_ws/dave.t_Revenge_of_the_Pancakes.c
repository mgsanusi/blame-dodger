#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE * in;
FILE * out;
 char pancakes[101];
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
 int
main (void)
{
   int t, T, len, pos, count;
   char prev;
   in = new_fopen (fileNameIn, "r");
  out = new_fopen (fileNameOut, "w");
   fscanf (in, "%d", &T);
   for (t = 1; t <= T; t++)
    {
      fprintf (out, "Case #%d:", t);
      fscanf (in, "%s", pancakes);
      len = strlen (pancakes);
      prev = '+';
      count = 0;
      for (pos = len - 1; pos >= 0; --pos)
	{
	  if (pancakes[pos] != prev)
	    {
	      ++count;
	      prev = pancakes[pos];
	    }
	}
      fprintf (out, " %d\n", count);
    }
   new_fclose (in);
  new_fclose (out);
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
