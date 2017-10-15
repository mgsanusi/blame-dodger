#include "src/core/lib/iomgr/port.h"
#include <uv.h>
#include <stddef.h>
#include <stddef.h>
#include <grpc/support/alloc.h>
#include <grpc/support/host_port.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include <grpc/support/useful.h>
#include "src/core/lib/iomgr/closure.h"
#include "src/core/lib/iomgr/error.h"
#include "src/core/lib/iomgr/exec_ctx.h"
#include "src/core/lib/iomgr/resolve_address.h"
#include "src/core/lib/iomgr/sockaddr.h"
#include "src/core/lib/iomgr/sockaddr_utils.h"
#include <string.h>
void *new_memset(void *ptr, int value, int num);
void *new_memcpy(void *destination, const void *source, int num);
void *new_memset(void *ptr, int value, int num);
void *new_memcpy(void *destination, const void *source, int num)
{
    return memcpy(destination, source, num);
}

void *new_memset(void *ptr, int value, int num)
{
    return memset(ptr, value, num);
}
