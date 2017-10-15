#include "src/core/lib/iomgr/port.h"
#include <limits.h>

#include <stddef.h>
#include "src/core/lib/iomgr/network_status_tracker.h"
#include "src/core/lib/iomgr/sockaddr_windows.h"
#include <grpc/slice_buffer.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/log_windows.h>
#include <grpc/support/string_util.h>
#include <grpc/support/useful.h>
#include "src/core/lib/iomgr/iocp_windows.h"
#include "src/core/lib/iomgr/sockaddr.h"
#include "src/core/lib/iomgr/sockaddr_utils.h"
#include "src/core/lib/iomgr/socket_windows.h"
#include "src/core/lib/iomgr/tcp_client.h"
#include "src/core/lib/iomgr/timer.h"
#include "src/core/lib/slice/slice_internal.h"
void * new_memset(void *ptr, int value, size_t num);



void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}