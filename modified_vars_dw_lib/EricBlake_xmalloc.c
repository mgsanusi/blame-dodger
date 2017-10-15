#include <config.h>
#include "xalloc.h"
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
void* new_calloc(int num, int size);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size);



void* new_calloc(int num, int size);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size) {
  return realloc(ptr, size);
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