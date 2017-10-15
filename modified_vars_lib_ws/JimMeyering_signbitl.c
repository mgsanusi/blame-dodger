#include <config.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "isnanl-nolibm.h"
#include "float+.h"
int new_memcmp (const void *ptr1, const void *ptr2, size_t num);
int
new_memcmp (const void *ptr1, const void *ptr2, size_t num)
{
  return memcmp (ptr1, ptr2, num);
}
