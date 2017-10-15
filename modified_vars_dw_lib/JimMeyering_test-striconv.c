#include <config.h>
#include "striconv.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

#include <stddef.h>
int new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2);

void new_free(void *ptr);

int new_memcmp(const void *ptr1, const void *ptr2, int num);



int new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2);

void new_free(void *ptr);

int new_memcmp(const void *ptr1, const void *ptr2, int num) {
  return memcmp(ptr1, ptr2, num);
}
int new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2);

void new_free(void *ptr) {
  return free(ptr);
}
int new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2) {
  return strcmp(str1, str2);
}
int new_strlen(const char *str) {
  return strlen(str);
}