#include "src/core/lib/support/string.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include <grpc/support/useful.h>
#include "test/core/util/test_config.h"
int new_strlen (const char *str);
int new_strcmp (const char *str1, const char *str2);
int new_strlen (const char *str);
int
new_strcmp (const char *str1, const char *str2)
{
  return strcmp (str1, str2);
}

int
new_strlen (const char *str)
{
  return strlen (str);
}
