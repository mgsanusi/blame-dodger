#include <config.h>
#include <stdio.h>
#include "stdio.h"
#include <string.h>
FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}
