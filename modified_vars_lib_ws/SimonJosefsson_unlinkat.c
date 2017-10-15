#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "dosname.h"
#include "openat.h"
void *new_malloc (size_t size);
void *new_memcpy (void *destination, const void *source, size_t num);
void new_free (void *ptr);
void *new_malloc (size_t size);
void *new_memcpy (void *destination, const void *source, size_t num);
void
new_free (void *ptr)
{
  return free (ptr);
}

void *new_malloc (size_t size);
void *
new_memcpy (void *destination, const void *source, size_t num)
{
  return memcpy (destination, source, num);
}

void *
new_malloc (size_t size)
{
  return malloc (size);
}
