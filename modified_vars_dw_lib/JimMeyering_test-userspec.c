#include <config.h>
#include "userspec.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stddef.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include "xalloc.h"
void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, int num);

void new_free(void *ptr);



void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, int num);

void new_free(void *ptr) {
  return free(ptr);
}
void new_assert(int expression);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
void new_assert(int expression) {
  return assert(expression);
}