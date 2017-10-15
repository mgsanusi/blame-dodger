#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/timer.h"
#include <string.h>

#include <stddef.h>
#include <grpc/support/log.h>
#include "src/core/lib/debug/trace.h"
#include "test/core/util/test_config.h"
void * new_memset(void *ptr, int value, int num);



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}