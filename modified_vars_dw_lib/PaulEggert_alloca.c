#include <config.h>
#include <alloca.h>
#include <string.h>
#include <stdlib.h>

#include <stddef.h>
typedef union hdr
void* new_malloc(int size);



void* new_malloc(int size) {
  return malloc(size);
}