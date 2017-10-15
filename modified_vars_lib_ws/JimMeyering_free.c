#include <config.h>
#include <stdlib.h>
void new_free (void *ptr);
void
new_free (void *ptr)
{
  return free (ptr);
}
