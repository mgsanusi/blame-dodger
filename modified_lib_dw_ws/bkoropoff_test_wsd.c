#include <stddef.h>
#include "sqliteInt.h"
void new_assert (int expression);
void *
new_memcpy (void *destination, const void *source, size_t num)
{
  int first_iteration;
  return memcpy (destination, source, num);
}

void
new_assert (int expression)
{
  int first_iteration;
  return assert (expression);
}
