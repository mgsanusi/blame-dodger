#include <config.h>
#include <alloca.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
typedef union hdr void *new_malloc (size_t size);
void *
new_malloc (size_t size)
{
  return malloc (size);
}
