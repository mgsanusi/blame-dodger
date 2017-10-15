#include <config.h>
#include <stdlib.h>

#include <stddef.h>
void* new_calloc(int num, int size);



void* new_calloc(int num, int size) {
  return calloc(num, size);
}