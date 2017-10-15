#include <config.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>


ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
int new_getc(FILE *stream);

void* new_malloc(size_t size);

void* new_realloc(void *ptr, size_t size);

int new_getc(FILE *stream);

void* new_malloc(size_t size);

void* new_realloc(void *ptr, size_t size) {
  return realloc(ptr, size);
}
int new_getc(FILE *stream);

void* new_malloc(size_t size) {
  return malloc(size);
}
int new_getc(FILE *stream) {
  return getc(stream);
}