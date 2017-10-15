#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/ev_epollsig_linux.h"
#include "src/core/lib/iomgr/ev_posix.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/thd.h>
#include <grpc/support/useful.h>
#include "src/core/lib/iomgr/iomgr.h"
#include "src/core/lib/iomgr/workqueue.h"
#include "test/core/util/test_config.h"
char *new_strerror(int errnum);
char *new_strerror(int errnum)
{
	return strerror(errnum);
}
