#include <config.h>
#include <stdlib.h>
#include <stddef.h>
void *new_calloc (size_t num, size_t size);
void *
new_calloc (size_t num, size_t size)
{
  return calloc (num, size);
}
