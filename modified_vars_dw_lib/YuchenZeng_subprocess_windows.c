#include <grpc/support/port_platform.h>
#include <string.h>
#include <tchar.h>
#include <windows.h>

#include <stddef.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/subprocess.h>
#include "src/core/lib/support/string.h"
#include "src/core/lib/support/string_windows.h"
void * new_memset(void *ptr, int value, int num);



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}