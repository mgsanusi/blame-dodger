#include <string.h>

#include <stddef.h>
#include "sys/mtarch.h"
void * new_memset(void *ptr, int value, int num);



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}