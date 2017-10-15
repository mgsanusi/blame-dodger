#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include "stdio-impl.h"
int new_getc(FILE *stream);

void new_free(void *ptr);



int new_getc(FILE *stream);

void new_free(void *ptr) {
  return free(ptr);
}
int new_getc(FILE *stream) {
  return getc(stream);
}