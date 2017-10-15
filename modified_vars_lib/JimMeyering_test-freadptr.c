#include <config.h>
#include "freadptr.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "macros.h"

#include <stddef.h>

#include <stddef.h>
void* new_malloc(size_t size);

int new_fgetc(FILE *stream);

int new_atoi(const char *str);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num);



void* new_malloc(size_t size);

int new_fgetc(FILE *stream);

int new_atoi(const char *str);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num) {
  return memcmp(ptr1, ptr2, num);
}
void* new_malloc(size_t size);

int new_fgetc(FILE *stream);

int new_atoi(const char *str) {
  return atoi(str);
}
void* new_malloc(size_t size);

int new_fgetc(FILE *stream) {
  return fgetc(stream);
}
void* new_malloc(size_t size) {
  return malloc(size);
}