#include <config.h>
#include "xmemdup0.h"
#include "xalloc.h"
#include <string.h>
#include <stddef.h>
void *new_memcpy (void *destination, const void *source, int num);
void *
new_memcpy (void *destination, const void *source, int num)
{
  return memcpy (destination, source, num);
}
