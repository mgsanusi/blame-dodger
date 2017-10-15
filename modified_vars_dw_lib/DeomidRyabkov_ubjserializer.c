#include <stdio.h>
#include <assert.h>

#include <stddef.h>

#include <stddef.h>
#include "common/ubjson.h"
#include "common/ubjserializer.h"
#include "common/cs_dbg.h"
int new_strlen(const char *str);

void* new_calloc(int num, int size);

void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, int num);

void new_free(void *ptr);



int new_strlen(const char *str);

void* new_calloc(int num, int size);

void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, int num);

void new_free(void *ptr) {
  return free(ptr);
}
int new_strlen(const char *str);

void* new_calloc(int num, int size);

void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
int new_strlen(const char *str);

void* new_calloc(int num, int size);

void new_assert(int expression) {
  return assert(expression);
}
int new_strlen(const char *str);

void* new_calloc(int num, int size) {
  return calloc(num, size);
}
int new_strlen(const char *str) {
  return strlen(str);
}