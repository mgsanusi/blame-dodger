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
void * new_memset(void *ptr, int value, int num);

int new_strlen(const char *str);

int new_memcmp(const void *ptr1, const void *ptr2, int num);



void * new_memset(void *ptr, int value, int num);

int new_strlen(const char *str);

int new_memcmp(const void *ptr1, const void *ptr2, int num) {
  return memcmp(ptr1, ptr2, num);
}
void * new_memset(void *ptr, int value, int num);

int new_strlen(const char *str) {
  return strlen(str);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}