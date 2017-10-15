#include "src/core/lib/iomgr/port.h"
#include <arpa/inet.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
#include <sys/socket.h>
#include <unistd.h>
#include <grpc/grpc.h>
#include <grpc/grpc_security.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include <grpc/support/thd.h>
#include "src/core/lib/iomgr/load_file.h"
#include "test/core/util/port.h"
#include "test/core/util/test_config.h"
size_t new_strlen(const char *str);

int new_strncmp(const char *str1, const char *str2, size_t num);



size_t new_strlen(const char *str);

int new_strncmp(const char *str1, const char *str2, size_t num) {
  return strncmp(str1, str2, num);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}