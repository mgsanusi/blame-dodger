#include <config.h>
#include "base64.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include <stddef.h>
void* new_malloc(size_t size);



void* new_malloc(size_t size) {
  return malloc(size);
}