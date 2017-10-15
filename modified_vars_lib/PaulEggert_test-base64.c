#include <config.h>
#include "base64.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "macros.h"

#include <stddef.h>

#include <stddef.h>
size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);


int new_memcmp(const void *ptr1, const void *ptr2, size_t num);



size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);


int new_memcmp(const void *ptr1, const void *ptr2, size_t num) {
  return memcmp(ptr1, ptr2, num);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}