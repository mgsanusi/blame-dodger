#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <stddef.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include "src/core/lib/json/json.h"
#include "test/core/util/memory_counters.h"
void * new_memcpy(void *destination, const void *source, int num);



void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}