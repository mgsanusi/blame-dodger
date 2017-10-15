#include <config.h>
#include "astrxfrm.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size);

void new_free(void *ptr);



void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size);

void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size) {
  return realloc(ptr, size);
}
void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
void* new_malloc(int size) {
  return malloc(size);
}