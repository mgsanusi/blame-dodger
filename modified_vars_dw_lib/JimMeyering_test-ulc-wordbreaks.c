#include <config.h>
#include "uniwbrk.h"
#include <locale.h>
#include <stdlib.h>
#include "macros.h"

#include <stddef.h>
void* new_malloc(int size);



void* new_malloc(int size) {
  return malloc(size);
}