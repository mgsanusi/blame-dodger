#include <config.h>

#include <stddef.h>
#include "resource-ext.h"
#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
void* new_malloc(int size);



void* new_malloc(int size) {
  return malloc(size);
}