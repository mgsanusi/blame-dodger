#include <config.h>
#include "unistr.h"
#include <string.h>

#include <stddef.h>
char * new_strncpy(char *destination, const char* source, size_t num);



char * new_strncpy(char *destination, const char* source, size_t num) {
  return strncpy(destination, source, num);
}