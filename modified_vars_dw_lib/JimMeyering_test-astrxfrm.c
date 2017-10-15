#include <config.h>
#include "astrxfrm.h"
#include <locale.h>
#include <string.h>
#include "macros.h"
int new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2);



int new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2) {
  return strcmp(str1, str2);
}
int new_strlen(const char *str) {
  return strlen(str);
}