#include <config.h>
#include "memcasecmp.h"
#include <string.h>
#include "zerosize-ptr.h"
#include "macros.h"
char * new_strcpy(char *destination, const char *source);



char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}