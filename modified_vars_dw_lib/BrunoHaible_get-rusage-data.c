#include <config.h>

#include <stddef.h>
#include "resource-ext.h"
#include <errno.h> /* errno */
#include <stdlib.h> /* size_t, abort, malloc, free, sbrk */
#include <fcntl.h> /* open, O_RDONLY */
#include <unistd.h> /* getpagesize, read, close */
#include "vma-iter.h"
#include <stdio.h>
int new_strlen(const char *str);

void* new_malloc(int size);



int new_strlen(const char *str);

void* new_malloc(int size) {
  return malloc(size);
}
int new_strlen(const char *str) {
  return strlen(str);
}