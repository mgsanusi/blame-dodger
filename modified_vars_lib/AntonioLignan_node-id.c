#include "sys/node-id.h"
#include "contiki-conf.h"
#include "dev/xmem.h"
#include <string.h>

#include <stddef.h>
void * new_memcpy(void *destination, const void *source, size_t num);



void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}