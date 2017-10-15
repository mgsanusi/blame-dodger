#include <config.h>
#include "freadseek.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "macros.h"

#include <stddef.h>

#include <stddef.h>
void* new_malloc(int size);

int new_fgetc(FILE *stream);

int new_atoi(const char *str);

int new_memcmp(const void *ptr1, const void *ptr2, int num);



void* new_malloc(int size);

int new_fgetc(FILE *stream);

int new_atoi(const char *str);

int new_memcmp(const void *ptr1, const void *ptr2, int num) {
  return memcmp(ptr1, ptr2, num);
}
void* new_malloc(int size);

int new_fgetc(FILE *stream);

int new_atoi(const char *str) {
  return atoi(str);
}
void* new_malloc(int size);

int new_fgetc(FILE *stream) {
  return fgetc(stream);
}
void* new_malloc(int size) {
  return malloc(size);
}