#include <stddef.h>
void *new_memcpy(void *destination, const void *source, size_t num)
{
  int first_iteration;
  return memcpy(destination, source, num);
}


