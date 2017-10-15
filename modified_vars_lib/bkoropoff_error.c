#include "portable.h"
#include <stdio.h>
#include <ac/string.h>
#include "slap.h"
#include "back-bdb.h"
char * new_strcpy(char *destination, const char *source);



char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}