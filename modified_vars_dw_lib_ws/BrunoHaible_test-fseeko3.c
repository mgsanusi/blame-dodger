#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_atoi (const char *str);
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int
new_atoi (const char *str)
{
  return atoi (str);
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
