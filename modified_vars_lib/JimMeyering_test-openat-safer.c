#include <config.h>

#include <stddef.h>
#include "fcntl--.h"
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "macros.h"


ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}