#include <config.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intprops.h"

#include <stddef.h>
#include "strerror-override.h"
#include "verify.h"
void * new_memcpy(void *destination, const void *source, size_t num);

char * new_strerror(int errnum);



void * new_memcpy(void *destination, const void *source, size_t num);

char * new_strerror(int errnum) {
  return strerror(errnum);
}
void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}