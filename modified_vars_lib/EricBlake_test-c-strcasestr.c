#include <config.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
#include "c-strcasestr.h"
#include <stdlib.h>
#include <string.h>
#include "macros.h"
size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);


void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void new_free(void *ptr);



size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);


void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void new_free(void *ptr) {
  return free(ptr);
}
size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);


void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);


void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}