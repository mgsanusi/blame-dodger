#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/ev_posix.h"
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/sync.h>
#include <grpc/support/time.h>
#include "src/core/lib/iomgr/ev_posix.h"
#include "src/core/lib/iomgr/iomgr.h"
#include "src/core/lib/iomgr/socket_utils_posix.h"
#include "test/core/util/test_config.h"
int new_read (int fd, void *buf, int count);
char *new_strerror (int errnum);
int new_read (int fd, void *buf, int count);
char *
new_strerror (int errnum)
{
  return strerror (errnum);
}

int
new_read (int fd, void *buf, int count)
{
  return read (fd, buf, count);
}
