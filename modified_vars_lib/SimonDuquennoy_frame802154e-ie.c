#include <string.h>

#include <stddef.h>
#include "net/mac/frame802154e-ie.h"
#include "net/net-debug.h"
void * new_memcpy(void *destination, const void *source, size_t num);



void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}