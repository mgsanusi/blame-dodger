#include "src/core/lib/iomgr/port.h"
#include <string.h>
#include <stddef.h>
#include <grpc/grpc.h>
#include <grpc/support/alloc.h>
#include <grpc/support/host_port.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include "src/core/lib/iomgr/resolve_address.h"
#include "src/core/lib/iomgr/socket_utils_posix.h"
#include "src/core/lib/slice/slice_string_helpers.h"
#include "src/core/lib/support/string.h"
#include "test/core/end2end/cq_verifier.h"
#include "test/core/util/port.h"
#include "test/core/util/test_config.h"
void *new_memset(void *ptr, int value, int num);
void *new_memset(void *ptr, int value, int num)
{
	return memset(ptr, value, num);
}
