#include "k5-int.h"
#include "os-proto.h"
#include <netinet/in.h>
void *new_memcpy (void *destination, const void *source, size_t num);
void *
new_memcpy (void *destination, const void *source, size_t num)
{
  return memcpy (destination, source, num);
}
