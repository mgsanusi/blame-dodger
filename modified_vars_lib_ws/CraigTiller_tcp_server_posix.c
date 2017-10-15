#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/tcp_server.h"
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include <grpc/support/sync.h>
#include <grpc/support/time.h>
#include <grpc/support/useful.h>
#include "src/core/lib/channel/channel_args.h"
#include "src/core/lib/iomgr/resolve_address.h"
#include "src/core/lib/iomgr/sockaddr.h"
#include "src/core/lib/iomgr/sockaddr_utils.h"
#include "src/core/lib/iomgr/socket_utils_posix.h"
#include "src/core/lib/iomgr/tcp_posix.h"
#include "src/core/lib/iomgr/tcp_server_utils_posix.h"
#include "src/core/lib/iomgr/unix_sockets_posix.h"
#include "src/core/lib/support/string.h"
void *new_memcpy(void *destination, const void *source, size_t num);
char *new_strerror(int errnum);
void *new_memcpy(void *destination, const void *source, size_t num);
char *new_strerror(int errnum)
{
    return strerror(errnum);
}

void *new_memcpy(void *destination, const void *source, size_t num)
{
    return memcpy(destination, source, num);
}
