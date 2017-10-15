#include <config.h>

#include <stddef.h>
#include "resource-ext.h"
#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
void* new_malloc(size_t size);



void* new_malloc(size_t size) {
  return malloc(size);
}