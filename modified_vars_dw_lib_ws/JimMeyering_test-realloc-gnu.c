#include <config.h>
#include <stdlib.h>
#include <stddef.h>
void *new_realloc (void *ptr, int size);
void *
new_realloc (void *ptr, int size)
{
  return realloc (ptr, size);
}
