#include "common/platforms/simplelink/sl_net_if.h"
#include "mongoose/src/internal.h"
#include "mongoose/src/util.h"
void * new_memcpy(void *destination, const void *source, size_t num);


void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}