#include <config.h>
#include "uniconv.h"
#include <stdlib.h>
#include <string.h>
#include "unistr.h"
#include "macros.h"

#include <stddef.h>
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

void new_free(void *ptr);



size_t new_strlen(const char *str);

void* new_malloc(size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}