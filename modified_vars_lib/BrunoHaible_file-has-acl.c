#include <config.h>
#include "acl.h"

#include <stddef.h>
#include "acl-internal.h"
void* new_malloc(size_t size);

void new_free(void *ptr);



void* new_malloc(size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(size_t size) {
  return malloc(size);
}