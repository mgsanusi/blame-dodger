#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/wakeup_fd_posix.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <grpc/support/log.h>
#include "src/core/lib/iomgr/socket_utils_posix.h"
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
