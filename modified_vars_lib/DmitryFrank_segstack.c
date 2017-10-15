#include "segstack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
void * new_memset(void *ptr, int value, size_t num);

void* new_calloc(size_t num, size_t size);

void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, size_t num);



void * new_memset(void *ptr, int value, size_t num);

void* new_calloc(size_t num, size_t size);

void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
void * new_memset(void *ptr, int value, size_t num);

void* new_calloc(size_t num, size_t size);

void new_assert(int expression) {
  return assert(expression);
}
void * new_memset(void *ptr, int value, size_t num);

void* new_calloc(size_t num, size_t size) {
  return calloc(num, size);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}