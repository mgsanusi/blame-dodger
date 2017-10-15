#include "src/core/lib/iomgr/port.h"
#include <uv.h>
#include <string.h>

#include <stddef.h>
#include "src/core/lib/iomgr/tcp_client.h"
#include <grpc/grpc.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/time.h>
#include "src/core/lib/iomgr/iomgr.h"
#include "src/core/lib/iomgr/pollset.h"
#include "src/core/lib/iomgr/timer.h"
#include "test/core/util/test_config.h"
void * new_memset(void *ptr, int value, size_t num);



void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}