#include "ksu.h"
#include <stdarg.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
#include "k5-platform.h"
void* new_calloc(int num, int size);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void new_exit(int status);

void* new_realloc(void *ptr, int size);



void* new_calloc(int num, int size);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void new_exit(int status);

void* new_realloc(void *ptr, int size) {
  return realloc(ptr, size);
}
void* new_calloc(int num, int size);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void new_exit(int status) {
  return exit(status);
}
void* new_calloc(int num, int size);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
void* new_calloc(int num, int size);

void* new_malloc(int size) {
  return malloc(size);
}
void* new_calloc(int num, int size) {
  return calloc(num, size);
}