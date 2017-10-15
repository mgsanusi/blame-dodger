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
int new_strlen(const char *str);

int new_read(int fd, void *buf, int count);



int new_strlen(const char *str);

int new_read(int fd, void *buf, int count) {
  return read(fd, buf, count);
}
int new_strlen(const char *str) {
  return strlen(str);
}