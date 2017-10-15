#include <config.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
#include "progname.h"
#include "read-file.h"
#include "xalloc.h"
#include "macros.h"
int new_fprintf (FILE * stream, const char *format, ...);
int new_memcmp (const void *ptr1, const void *ptr2, int num);
int new_fprintf (FILE * stream, const char *format, ...);
int
new_memcmp (const void *ptr1, const void *ptr2, int num)
{
  return memcmp (ptr1, ptr2, num);
}
