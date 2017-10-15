#include <stdlib.h>

#include <stddef.h>

#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>
#include "common/platforms/esp/src/esp_mmap.h"
#include "common/cs_dbg.h"
#include "common/mbuf.h"
#include "common/spiffs/spiffs.h"
#include "common/spiffs/spiffs_nucleus.h"
void * new_memset(void *ptr, int value, size_t num);

void* new_calloc(size_t num, size_t size);



void * new_memset(void *ptr, int value, size_t num);

void* new_calloc(size_t num, size_t size) {
  return calloc(num, size);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}