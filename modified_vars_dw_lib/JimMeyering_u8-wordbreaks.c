#include <config.h>
#include "uniwbrk.h"
#include <string.h>
#include "unistr.h"

#include <stddef.h>

#include <stddef.h>
#include "uniwbrk/wbrktable.h"
#include "u-wordbreaks.h"
#include <stdio.h>
#include <stdlib.h>
void* new_malloc(int size);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

void* new_realloc(void *ptr, int size);



void* new_malloc(int size);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

void* new_realloc(void *ptr, int size) {
  return realloc(ptr, size);
}
void* new_malloc(int size);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status) {
  return exit(status);
}
void* new_malloc(int size) {
  return malloc(size);
}