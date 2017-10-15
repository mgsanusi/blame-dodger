#include <config.h>
#include "progname.h"
#include <errno.h> /* get program_invocation_name declaration */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
int new_strncmp(const char *str1, const char *str2, size_t num);



int new_strncmp(const char *str1, const char *str2, size_t num) {
  return strncmp(str1, str2, num);
}