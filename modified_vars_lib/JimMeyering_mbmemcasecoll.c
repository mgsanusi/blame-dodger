#include <config.h>
#include "mbmemcasecoll.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include "malloca.h"
#include "memcmp2.h"
#include "memcoll.h"

#include <stddef.h>

#include <stddef.h>
void * new_memset(void *ptr, int value, size_t num);

int new_isupper(int c);

int new_tolower(int c);

void * new_memcpy(void *destination, const void *source, size_t num);



void * new_memset(void *ptr, int value, size_t num);

int new_isupper(int c);

int new_tolower(int c);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
void * new_memset(void *ptr, int value, size_t num);

int new_isupper(int c);

int new_tolower(int c) {
  return tolower(c);
}
void * new_memset(void *ptr, int value, size_t num);

int new_isupper(int c) {
  return isupper(c);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}