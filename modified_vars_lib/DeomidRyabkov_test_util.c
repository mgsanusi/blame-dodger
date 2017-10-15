#include "common/test_util.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>
#include <sys/time.h>
#include <windows.h>
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

void new_free(void *ptr);

int new_strncmp(const char *str1, const char *str2, size_t num);



size_t new_strlen(const char *str);

void* new_malloc(size_t size);

void new_free(void *ptr);

int new_strncmp(const char *str1, const char *str2, size_t num) {
  return strncmp(str1, str2, num);
}
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