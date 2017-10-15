#include <grpc/support/port_platform.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <grpc/support/alloc.h>
void *new_memcpy (void *destination, const void *source, size_t num);
void *
new_memcpy (void *destination, const void *source, size_t num)
{
  return memcpy (destination, source, num);
}
