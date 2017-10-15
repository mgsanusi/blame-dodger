#include "common/ubjson.h"
void new_assert (int expression);
void *new_memcpy (void *destination, const void *source, int num);
void new_assert (int expression);
void *
new_memcpy (void *destination, const void *source, int num)
{
  return memcpy (destination, source, num);
}

void
new_assert (int expression)
{
  return assert (expression);
}
