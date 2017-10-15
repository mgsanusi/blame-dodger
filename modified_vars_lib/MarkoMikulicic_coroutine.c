#include <string.h>
#include <stdlib.h>

#include <stddef.h>
#include "common/coroutine.h"
void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, size_t num);



void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
void new_assert(int expression) {
  return assert(expression);
}