#include <config.h>
#include <stddef.h>
#include <stddef.h>
#include "concat-filename.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "filename.h"
int new_strlen (const char *str);
void *new_malloc (int size);
void *new_memcpy (void *destination, const void *source, int num);
int new_strlen (const char *str);
void *new_malloc (int size);
void *
new_memcpy (void *destination, const void *source, int num)
{
  return memcpy (destination, source, num);
}

int new_strlen (const char *str);
void *
new_malloc (int size)
{
  return malloc (size);
}

int
new_strlen (const char *str)
{
  return strlen (str);
}
