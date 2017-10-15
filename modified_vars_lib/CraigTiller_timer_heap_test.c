#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/timer_heap.h"
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/useful.h>
#include "test/core/util/test_config.h"
void * new_memset(void *ptr, int value, size_t num);

int new_rand();



void * new_memset(void *ptr, int value, size_t num);

int new_rand() {
  return rand();
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}