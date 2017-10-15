#include <config.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "sys/stat.h"
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include "dosname.h"
#include "verify.h"
int new_strlen(const char *str);

char * new_strcpy(char *destination, const char *source);



int new_strlen(const char *str);

char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}
int new_strlen(const char *str) {
  return strlen(str);
}