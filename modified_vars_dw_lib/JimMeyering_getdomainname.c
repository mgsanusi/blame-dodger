#include <config.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

#include <stddef.h>
void * new_memcpy(void *destination, const void *source, int num);



void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}