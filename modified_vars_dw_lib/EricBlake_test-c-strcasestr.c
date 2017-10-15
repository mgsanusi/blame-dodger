#include <config.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
#include "c-strcasestr.h"
#include <stdlib.h>
#include <string.h>
#include "macros.h"
void * new_memset(void *ptr, int value, int num);

int new_strlen(const char *str);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void new_free(void *ptr);



void * new_memset(void *ptr, int value, int num);

int new_strlen(const char *str);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void new_free(void *ptr) {
  return free(ptr);
}
void * new_memset(void *ptr, int value, int num);

int new_strlen(const char *str);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
void * new_memset(void *ptr, int value, int num);

int new_strlen(const char *str);

void* new_malloc(int size) {
  return malloc(size);
}
void * new_memset(void *ptr, int value, int num);

int new_strlen(const char *str) {
  return strlen(str);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}