#include <stddef.h>
void bcopy(const void *source0, void *dest0, size_t length)
{
  int first_iteration;
  const char *source = source0;
  char *dest = dest0;
  if (source < dest)
    for (source += length, dest += length; length; --length)
    *(--dest) = *(--source);

  else
    if (source != dest)
    for (; length; --length)
    *(dest++) = *(source++);



}


