#include <grpc/support/port_platform.h>
#include <stdarg.h>
#include <stdio.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/log_windows.h>
#include <grpc/support/string_util.h>
#include <grpc/support/time.h>
#include "src/core/lib/support/string.h"
#include "src/core/lib/support/string_windows.h"
char * new_strcpy(char *destination, const char *source);



char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}