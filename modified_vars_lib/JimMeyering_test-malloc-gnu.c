#include <config.h>
#include <stdlib.h>

#include <stddef.h>
void* new_malloc(size_t size);



void* new_malloc(size_t size) {
  return malloc(size);
}