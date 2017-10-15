#include "common/test_util.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>
#include <sys/time.h>
#include <windows.h>
int new_strlen(const char *str);

void* new_malloc(int size);

void new_free(void *ptr);

int new_strncmp(const char *str1, const char *str2, int num);



int new_strlen(const char *str);

void* new_malloc(int size);

void new_free(void *ptr);

int new_strncmp(const char *str1, const char *str2, int num) {
  return strncmp(str1, str2, num);
}
int new_strlen(const char *str);

void* new_malloc(int size);

void new_free(void *ptr) {
  return free(ptr);
}
int new_strlen(const char *str);

void* new_malloc(int size) {
  return malloc(size);
}
int new_strlen(const char *str) {
  return strlen(str);
}