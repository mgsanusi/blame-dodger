#include <config.h>
#include <float.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>
#include "float+.h"
typedef union { DOUBLE value; unsigned int word[NWORDS]; } memory_double;
void * new_memset(void *ptr, int value, size_t num);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num);



void * new_memset(void *ptr, int value, size_t num);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num) {
  return memcmp(ptr1, ptr2, num);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}