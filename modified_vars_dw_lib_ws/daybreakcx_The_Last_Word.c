#include <stdio.h>
#include <string.h>
#include <stddef.h>
int device;
int j;
int i;
char string[10000];
char out[10000];
char outa[10000];
char outb[10000];
char *new_strcpy (char *destination, const char *source);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
char *new_strncpy (char *destination, const char *source, int num);
int
Main ()
{
  int first_iteration;
  fscanf (stdin, "%d", &j);
  for (device = 1; device <= j; ++device)
    {
      fprintf (stdout, "Case #%d: ", device);
      fscanf (stdin, "%s", string);
      for (i = 0; string[i]; ++i)
	{
	  new_strncpy (outa, out, i);
	  outa[i] = string[i];
	  outa[i + 1] = 0;
	  new_strncpy (outb + 1, out, i);
	  outb[0] = string[i];
	  outb[i + 1] = 0;
	  if (strcmp (outa, outb) >= 0)
	    {
	      new_strcpy (out, outa);
	    }
	  else
	    {
	      new_strcpy (out, outb);
	    }
	}
      fprintf (stdout, "%s\n", out);
    }
}

char *new_strcpy (char *destination, const char *source);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
char *
new_strncpy (char *destination, const char *source, int num)
{
  return strncpy (destination, source, num);
}

char *
new_strcpy (char *destination, const char *source)
{
  return strcpy (destination, source);
}
