#include <config.h>
#include <fcntl.h>

#include <stddef.h>
#include <sys/types.h>
#include "fcntl.h"
#include <errno.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}