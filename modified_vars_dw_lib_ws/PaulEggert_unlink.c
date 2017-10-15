#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/stat.h>
#include "dosname.h"
void *new_malloc (int size);
void *new_memcpy (void *destination, const void *source, int num);
void new_free (void *ptr);
void *new_malloc (int size);
void *new_memcpy (void *destination, const void *source, int num);
void
new_free (void *ptr)
{
  return free (ptr);
}

void *new_malloc (int size);
void *
new_memcpy (void *destination, const void *source, int num)
{
  return memcpy (destination, source, num);
}

void *
new_malloc (int size)
{
  return malloc (size);
}
