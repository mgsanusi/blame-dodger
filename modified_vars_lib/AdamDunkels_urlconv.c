#include <string.h>

#include <stddef.h>
#include "cfs/cfs.h"
#include "http-strings.h"
char * new_strcpy(char *destination, const char *source);

char * new_strncpy(char *destination, const char* source, size_t num);



char * new_strcpy(char *destination, const char *source);

char * new_strncpy(char *destination, const char* source, size_t num) {
  return strncpy(destination, source, num);
}
char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}