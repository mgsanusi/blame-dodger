#include <config.h>
#include "memcmp2.h"
#include <string.h>

#include <stddef.h>
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);



int new_memcmp(const void *ptr1, const void *ptr2, size_t num) {
  return memcmp(ptr1, ptr2, num);
}