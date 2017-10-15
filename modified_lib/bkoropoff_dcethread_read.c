/* Clean */

#include <config.h>
#include <unistd.h>

#include <stddef.h>

#include "dcethread-private.h"
#include "dcethread-util.h"
#include "dcethread-debug.h"
#include "dcethread-exception.h"

#ifdef API

ssize_t
dcethread_new_read(int fd, void *buf, size_t count)
{
    DCETHREAD_SYSCALL(ssize_t, new_read(fd, buf, count));
}

#endif /* API */

ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}