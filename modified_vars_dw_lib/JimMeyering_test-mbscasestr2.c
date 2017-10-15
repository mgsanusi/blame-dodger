#include <config.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "macros.h"

#include <stddef.h>

#include <stddef.h>
void * new_memset(void *ptr, int value, int num);

void* new_malloc(int size);

void new_free(void *ptr);



void * new_memset(void *ptr, int value, int num);

void* new_malloc(int size);

void new_free(void *ptr) {
  return free(ptr);
}
void * new_memset(void *ptr, int value, int num);

void* new_malloc(int size) {
  return malloc(size);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}