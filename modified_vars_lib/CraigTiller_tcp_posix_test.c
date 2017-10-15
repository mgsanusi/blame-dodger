#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/tcp_posix.h"
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#include <stddef.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <grpc/grpc.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/time.h>
#include <grpc/support/useful.h>
#include "src/core/lib/slice/slice_internal.h"
#include "test/core/iomgr/endpoint_tests.h"
#include "test/core/util/test_config.h"


ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}