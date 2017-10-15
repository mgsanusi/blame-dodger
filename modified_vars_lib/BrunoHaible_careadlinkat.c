#include <config.h>
#include "careadlinkat.h"
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "allocator.h"

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void* new_realloc(void *ptr, size_t size);



void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void* new_realloc(void *ptr, size_t size) {
  return realloc(ptr, size);
}
void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
void* new_malloc(size_t size) {
  return malloc(size);
}