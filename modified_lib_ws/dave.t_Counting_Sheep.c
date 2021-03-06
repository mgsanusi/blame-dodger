#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE * in;
FILE * out;
 int seen[10];
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
 void
reset (void)
{
  int i;
  for (i = 0; i < 10; ++i)
    {
      seen[i] = 0;
    }
}

 int
done (void)
{
  int i;
  for (i = 0; i < 10; ++i)
    {
      if (seen[i] == 0)
	return 0;
    }
  return 1;
}

 void
parse (long long v)
{
  while (v)
    {
      seen[v % 10] = 1;
      v /= 10;
    }
}

 int
main (void)
{
   int n, N, T, k;
   long long v;
   in = new_fopen (fileNameIn, "r");
  out = new_fopen (fileNameOut, "w");
   fscanf (in, "%d", &N);
   for (n = 1; n <= N; ++n)
    {
      fprintf (out, "Case #%d: ", n);
       fscanf (in, "%d", &T);
       if (T == 0)
	{
	  fprintf (out, "INSOMNIA\n");
	  continue;
	}
      reset ();
       k = 1;
      v = T;
      while (1)
	{
	  parse (v);
	  if (done ())
	    break;
	  ++k;
	  v += T;
	}
      fprintf (out, "%lld\n", v);
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
