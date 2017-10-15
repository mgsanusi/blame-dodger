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