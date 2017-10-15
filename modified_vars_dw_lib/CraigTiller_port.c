#include "src/core/lib/iomgr/port.h"
#include "test/core/util/test_config.h"
#include "test/core/util/port.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <grpc/grpc.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include "src/core/lib/http/httpcli.h"
#include "src/core/lib/iomgr/resolve_address.h"
#include "src/core/lib/iomgr/sockaddr_utils.h"
#include "test/core/util/port_server_client.h"
void new_exit(int status);



void new_exit(int status) {
  return exit(status);
}