#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/wakeup_fd_posix.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <grpc/support/log.h>
#include "src/core/lib/iomgr/socket_utils_posix.h"
ssize_t new_read(int fd, void *buf, size_t count);
char *new_strerror(int errnum);
ssize_t new_read(int fd, void *buf, size_t count);
char *new_strerror(int errnum)
{
    return strerror(errnum);
}

ssize_t new_read(int fd, void *buf, size_t count)
{
    return read(fd, buf, count);
}
