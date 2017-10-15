#include "contiki.h"
#include <stddef.h>
#include "lib/random.h"
#include "net/rime/rime.h"
#include "net/rime/timesynch.h"
#include <string.h>
void *new_memcpy (void *destination, const void *source, int num);
void *
new_memcpy (void *destination, const void *source, int num)
{
  return memcpy (destination, source, num);
}
