#include <config.h>
#include "striconv.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>
#include "c-strcase.h"
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

void* new_realloc(void *ptr, size_t size);

void new_free(void *ptr);



size_t new_strlen(const char *str);

void* new_malloc(size_t size);

void* new_realloc(void *ptr, size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

void* new_realloc(void *ptr, size_t size) {
  return realloc(ptr, size);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}