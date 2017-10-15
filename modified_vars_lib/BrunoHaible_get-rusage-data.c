#include <config.h>

#include <stddef.h>
#include "resource-ext.h"
#include <errno.h> /* errno */
#include <stdlib.h> /* size_t, abort, malloc, free, sbrk */
#include <fcntl.h> /* open, O_RDONLY */
#include <unistd.h> /* getpagesize, read, close */
#include "vma-iter.h"
#include <stdio.h>
size_t new_strlen(const char *str);

void* new_malloc(size_t size);



size_t new_strlen(const char *str);

void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}