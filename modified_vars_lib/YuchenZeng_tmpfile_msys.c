#include <grpc/support/port_platform.h>
#include <io.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include "src/core/lib/support/string_windows.h"
#include "src/core/lib/support/tmpfile.h"


FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}