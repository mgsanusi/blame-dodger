#include <config.h>
#include "stdio-safer.h"
#include <errno.h>
#include <unistd.h>
#include "unistd-safer.h"
FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

int new_fclose (FILE * stream);
int
new_fclose (FILE * stream)
{
  return fclose (stream);
}
