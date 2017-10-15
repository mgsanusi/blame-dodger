#include <stdlib.h>

#include <stddef.h>
#include "../ff.h"
void* new_malloc(int size);



void* new_malloc(int size) {
  return malloc(size);
}