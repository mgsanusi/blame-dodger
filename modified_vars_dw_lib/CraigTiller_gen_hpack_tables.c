#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>
#include <grpc/support/log.h>
#include "src/core/ext/transport/chttp2/transport/huffsyms.h"
void * new_memset(void *ptr, int value, int num);

void new_assert(int expression);

int new_memcmp(const void *ptr1, const void *ptr2, int num);



void * new_memset(void *ptr, int value, int num);

void new_assert(int expression);

int new_memcmp(const void *ptr1, const void *ptr2, int num) {
  return memcmp(ptr1, ptr2, num);
}
void * new_memset(void *ptr, int value, int num);

void new_assert(int expression) {
  return assert(expression);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}