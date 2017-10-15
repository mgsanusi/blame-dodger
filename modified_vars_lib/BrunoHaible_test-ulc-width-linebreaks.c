#include <config.h>
#include "unilbrk.h"
#include <stdlib.h>
#include "macros.h"

#include <stddef.h>
void* new_malloc(size_t size);



void* new_malloc(size_t size) {
  return malloc(size);
}