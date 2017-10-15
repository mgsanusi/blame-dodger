#include <config.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
#include "safe-alloc.h"
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
void* new_calloc(int num, int size);

void* new_malloc(int size);

void* new_realloc(void *ptr, int size);



void* new_calloc(int num, int size);

void* new_malloc(int size);

void* new_realloc(void *ptr, int size) {
  return realloc(ptr, size);
}
void* new_calloc(int num, int size);

void* new_malloc(int size) {
  return malloc(size);
}
void* new_calloc(int num, int size) {
  return calloc(num, size);
}