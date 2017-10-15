#include <string.h>

#include <stddef.h>
#include "sys/mtarch.h"
void * new_memset(void *ptr, int value, size_t num);



void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}