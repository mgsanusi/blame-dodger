#include <config.h>

#include <stddef.h>
#include "fcntl--.h"
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "macros.h"
int new_read(int fd, void *buf, int count);



int new_read(int fd, void *buf, int count) {
  return read(fd, buf, count);
}