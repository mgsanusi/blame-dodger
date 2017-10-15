#include <config.h>
#include "unicase.h"

#include <stddef.h>
#include "u-totitle.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

void* new_realloc(void *ptr, size_t size);



int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

void* new_realloc(void *ptr, size_t size) {
  return realloc(ptr, size);
}
int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status) {
  return exit(status);
}