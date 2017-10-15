#include <config.h>
#include <stdlib.h>
#include <errno.h>

#include <stddef.h>
void* new_malloc(int size);



void* new_malloc(int size) {
  return malloc(size);
}