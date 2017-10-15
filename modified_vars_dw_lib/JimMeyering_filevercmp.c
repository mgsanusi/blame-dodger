#include <config.h>
#include "filevercmp.h"

#include <stddef.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <c-ctype.h>
#include <limits.h>
int new_strcmp(const char *str1, const char *str2);

int new_strncmp(const char *str1, const char *str2, int num);



int new_strcmp(const char *str1, const char *str2);

int new_strncmp(const char *str1, const char *str2, int num) {
  return strncmp(str1, str2, num);
}
int new_strcmp(const char *str1, const char *str2) {
  return strcmp(str1, str2);
}