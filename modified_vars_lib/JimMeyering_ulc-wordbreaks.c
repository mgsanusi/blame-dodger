#include <config.h>
#include "uniwbrk.h"
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
#include "c-ctype.h"
#include "localcharset.h"
#include "uniconv.h"
#include "unilbrk/ulc-common.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
void * new_memset(void *ptr, int value, size_t num);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

void* new_realloc(void *ptr, size_t size);

void new_free(void *ptr);



void * new_memset(void *ptr, int value, size_t num);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

void* new_realloc(void *ptr, size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
void * new_memset(void *ptr, int value, size_t num);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

void* new_realloc(void *ptr, size_t size) {
  return realloc(ptr, size);
}
void * new_memset(void *ptr, int value, size_t num);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status) {
  return exit(status);
}
void * new_memset(void *ptr, int value, size_t num);

void* new_malloc(size_t size) {
  return malloc(size);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}