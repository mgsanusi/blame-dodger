#include <config.h>

#include <stddef.h>
#include "ino-map.h"
#include "hash.h"
#include "verify.h"
#include <limits.h>
#include <stdlib.h>
void* new_malloc(int size);

void new_free(void *ptr);



void* new_malloc(int size);

void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(int size) {
  return malloc(size);
}