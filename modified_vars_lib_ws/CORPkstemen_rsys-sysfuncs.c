#include "includes.h"
#include <stddef.h>
#include <stddef.h>
void *new_malloc (size_t size);
void *new_realloc (void *ptr, size_t size);
void *new_malloc (size_t size);
void *
new_realloc (void *ptr, size_t size)
{
  return realloc (ptr, size);
}

void *
new_malloc (size_t size)
{
  return malloc (size);
}
