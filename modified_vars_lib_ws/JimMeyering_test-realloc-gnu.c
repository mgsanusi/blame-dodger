#include <config.h>
#include <stdlib.h>
#include <stddef.h>
void *new_realloc (void *ptr, size_t size);
void *
new_realloc (void *ptr, size_t size)
{
  return realloc (ptr, size);
}
