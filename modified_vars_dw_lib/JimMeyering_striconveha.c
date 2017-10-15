#include <config.h>
#include "striconveha.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "malloca.h"

#include <stddef.h>

#include <stddef.h>
#include "c-strcase.h"
#include "striconveh.h"
int new_strlen(const char *str);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);



int new_strlen(const char *str);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
int new_strlen(const char *str);

void* new_malloc(int size) {
  return malloc(size);
}
int new_strlen(const char *str) {
  return strlen(str);
}