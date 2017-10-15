#include <pe>

#include <stddef.h>
const int maxp = 100000;
void * new_memset(void *ptr, int value, size_t num);



void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}