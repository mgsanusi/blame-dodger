#include <string.h>

#include <stddef.h>
#include "cfs/cfs.h"
#include "http-strings.h"
char * new_strcpy(char *destination, const char *source);

char * new_strncpy(char *destination, const char* source, int num);



char * new_strcpy(char *destination, const char *source);

char * new_strncpy(char *destination, const char* source, int num) {
  return strncpy(destination, source, num);
}
char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}