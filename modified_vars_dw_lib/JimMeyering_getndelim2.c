#include <config.h>
#include "getndelim2.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include "freadptr.h"
#include "freadseek.h"
#include "memchr2.h"

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
int new_getc(FILE *stream);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size);



int new_getc(FILE *stream);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size) {
  return realloc(ptr, size);
}
int new_getc(FILE *stream);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
int new_getc(FILE *stream);

void* new_malloc(int size) {
  return malloc(size);
}
int new_getc(FILE *stream) {
  return getc(stream);
}