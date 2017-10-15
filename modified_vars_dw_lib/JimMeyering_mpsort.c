#include <config.h>
#include "mpsort.h"
#include <string.h>

#include <stddef.h>
typedef int (*comparison_function) (void const *, void const *);
void * new_memcpy(void *destination, const void *source, int num);



void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}