#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include "er-coap.h"
#include "er-coap-observe-client.h"
void *new_memcpy (void *destination, const void *source, size_t num);
int new_memcmp (const void *ptr1, const void *ptr2, size_t num);
void *new_memcpy (void *destination, const void *source, size_t num);
int
new_memcmp (const void *ptr1, const void *ptr2, size_t num)
{
  return memcmp (ptr1, ptr2, num);
}

void *
new_memcpy (void *destination, const void *source, size_t num)
{
  return memcpy (destination, source, num);
}
