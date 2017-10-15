#include <config.h>

#include <stddef.h>

#include <stddef.h>
#include "concat-filename.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "filename.h"
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);



size_t new_strlen(const char *str);

void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}