#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/ev_posix.h"
#include <string.h>
#include <stddef.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include <grpc/support/useful.h>
#include "src/core/lib/debug/trace.h"
#include "src/core/lib/iomgr/ev_epoll1_linux.h"
#include "src/core/lib/iomgr/ev_epoll_limited_pollers_linux.h"
#include "src/core/lib/iomgr/ev_epoll_thread_pool_linux.h"
#include "src/core/lib/iomgr/ev_epollex_linux.h"
#include "src/core/lib/iomgr/ev_epollsig_linux.h"
#include "src/core/lib/iomgr/ev_poll_posix.h"
#include "src/core/lib/support/env.h"
typedef const grpc_event_engine_vtable *(*event_engine_factory_fn) (char
								    *new_strchr
								    (char
								     *str,
								     int
								     character);
								    int
								    new_strcmp
								    (const
								     char
								     *str1,
								     const
								     char
								     *str2);
								    void
								    *new_memcpy
								    (void
								     *destination,
								     const
								     void
								     *source,
								     size_t
								     num);
								    char
								    *new_strchr
								    (char
								     *str,
								     int
								     character);
								    int
								    new_strcmp
								    (const
								     char
								     *str1,
								     const
								     char
								     *str2);
								    void
								    *new_memcpy
								    (void
								     *destination,
								     const
								     void
								     *source,
								     size_t
								     num)
								    {
								    return
								    memcpy
								    (destination,
								     source,
								     num);}
								    char
								    *new_strchr
								    (char
								     *str,
								     int
								     character);
								    int
								    new_strcmp
								    (const
								     char
								     *str1,
								     const
								     char
								     *str2)
								    {
								    return
								    strcmp
								    (str1,
								     str2);}
								    char
								    *new_strchr
								    (char
								     *str,
								     int
								     character)
								    {
								    return
								    strchr
								    (str,
								     character);}
