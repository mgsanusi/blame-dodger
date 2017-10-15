#include <config.h>
#include "unistr.h"
#include <string.h>
char * new_strcat(char *destination, const char *source);



char * new_strcat(char *destination, const char *source) {
  return strcat(destination, source);
}