#include <config.h>

#include <stddef.h>

#include <stddef.h>
#include "read-file.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size);

void* new_realloc(void *ptr, size_t size);

void new_free(void *ptr);



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size);

void* new_realloc(void *ptr, size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size);

void* new_realloc(void *ptr, size_t size) {
  return realloc(ptr, size);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size) {
  return malloc(size);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}