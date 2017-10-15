#include <stdio.h>
#include <assert.h>

#include <stddef.h>

#include <stddef.h>
#include "common/ubjson.h"
#include "common/ubjserializer.h"
#include "common/cs_dbg.h"
size_t new_strlen(const char *str);

void* new_calloc(size_t num, size_t size);

void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, size_t num);

void new_free(void *ptr);



size_t new_strlen(const char *str);

void* new_calloc(size_t num, size_t size);

void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, size_t num);

void new_free(void *ptr) {
  return free(ptr);
}
size_t new_strlen(const char *str);

void* new_calloc(size_t num, size_t size);

void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
size_t new_strlen(const char *str);

void* new_calloc(size_t num, size_t size);

void new_assert(int expression) {
  return assert(expression);
}
size_t new_strlen(const char *str);

void* new_calloc(size_t num, size_t size) {
  return calloc(num, size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}