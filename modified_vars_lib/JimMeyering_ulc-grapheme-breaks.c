#include <config.h>
#include "unigbrk.h"
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>
#include "c-ctype.h"
#include "c-strcaseeq.h"
#include "localcharset.h"
#include "uniconv.h"
void * new_memset(void *ptr, int value, size_t num);

void* new_malloc(size_t size);

void new_free(void *ptr);



void * new_memset(void *ptr, int value, size_t num);

void* new_malloc(size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
void * new_memset(void *ptr, int value, size_t num);

void* new_malloc(size_t size) {
  return malloc(size);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}