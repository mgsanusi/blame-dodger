#include <stdio.h>
#include <string.h>
#include "cystring.h"
#include "cysort.h"
#include <stddef.h>
FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}

void *new_memset (void *ptr, int value, int num);
void *
new_memset (void *ptr, int value, int num)
{
  return memset (ptr, value, num);
}
