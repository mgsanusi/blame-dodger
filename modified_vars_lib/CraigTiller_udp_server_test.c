#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/udp_server.h"
#include <netinet/in.h>
#include <string.h>

#include <stddef.h>
#include <sys/socket.h>
#include <unistd.h>
#include <grpc/grpc.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/sync.h>
#include <grpc/support/time.h>
#include <grpc/support/useful.h>
#include "src/core/lib/channel/channel_args.h"
#include "src/core/lib/iomgr/ev_posix.h"
#include "src/core/lib/iomgr/iomgr.h"
#include "src/core/lib/iomgr/socket_factory_posix.h"
#include "test/core/util/test_config.h"
void * new_memset(void *ptr, int value, size_t num);



void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}