#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/tcp_server.h"
#include <errno.h>
#include <ifaddrs.h>
#include <stddef.h>
#include <stddef.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <grpc/grpc.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/sync.h>
#include <grpc/support/time.h>
#include "src/core/lib/iomgr/error.h"
#include "src/core/lib/iomgr/iomgr.h"
#include "src/core/lib/iomgr/resolve_address.h"
#include "src/core/lib/iomgr/sockaddr_utils.h"
#include "test/core/util/port.h"
#include "test/core/util/test_config.h"
void *new_memset (void *ptr, int value, int num);
void *new_memcpy (void *destination, const void *source, int num);
char *new_strerror (int errnum);
void *new_memset (void *ptr, int value, int num);
void *new_memcpy (void *destination, const void *source, int num);
char *
new_strerror (int errnum)
{
  return strerror (errnum);
}

void *new_memset (void *ptr, int value, int num);
void *
new_memcpy (void *destination, const void *source, int num)
{
  return memcpy (destination, source, num);
}

void *
new_memset (void *ptr, int value, int num)
{
  return memset (ptr, value, num);
}
