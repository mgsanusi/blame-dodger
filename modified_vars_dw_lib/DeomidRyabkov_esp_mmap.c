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
void * new_memset(void *ptr, int value, int num);

void* new_calloc(int num, int size);



void * new_memset(void *ptr, int value, int num);

void* new_calloc(int num, int size) {
  return calloc(num, size);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}