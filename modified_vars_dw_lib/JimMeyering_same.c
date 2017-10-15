#include <config.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include "same.h"
#include "dirname.h"
#include "error.h"
#include "same-inode.h"
void new_free(void *ptr);

int new_memcmp(const void *ptr1, const void *ptr2, int num);



void new_free(void *ptr);

int new_memcmp(const void *ptr1, const void *ptr2, int num) {
  return memcmp(ptr1, ptr2, num);
}
void new_free(void *ptr) {
  return free(ptr);
}