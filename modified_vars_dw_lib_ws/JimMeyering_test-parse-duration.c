#include <config.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "parse-duration.h"
int new_fprintf (FILE * stream, const char *format, ...);
char *new_strerror (int errnum);
int new_fprintf (FILE * stream, const char *format, ...);
char *
new_strerror (int errnum)
{
  return strerror (errnum);
}
