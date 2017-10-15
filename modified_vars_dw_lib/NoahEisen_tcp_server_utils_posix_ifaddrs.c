#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/tcp_server_utils_posix.h"
#include <errno.h>
#include <ifaddrs.h>
#include <stddef.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include "src/core/lib/iomgr/error.h"
#include "src/core/lib/iomgr/sockaddr.h"
#include "src/core/lib/iomgr/sockaddr_utils.h"
void * new_memcpy(void *destination, const void *source, int num);

int new_memcmp(const void *ptr1, const void *ptr2, int num);



void * new_memcpy(void *destination, const void *source, int num);

int new_memcmp(const void *ptr1, const void *ptr2, int num) {
  return memcmp(ptr1, ptr2, num);
}
void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}