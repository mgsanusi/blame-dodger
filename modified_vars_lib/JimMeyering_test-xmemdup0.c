#include <config.h>
#include "xmemdup0.h"
#include <stdlib.h>
#include <string.h>
#include "progname.h"
#include "macros.h"

#include <stddef.h>
void new_free(void *ptr);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num);



void new_free(void *ptr);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num) {
  return memcmp(ptr1, ptr2, num);
}
void new_free(void *ptr) {
  return free(ptr);
}