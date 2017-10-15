#include "common/mg_mem.h"
#include <lwip/init.h>
#include <lwip/pbuf.h>
#include <lwip/tcp.h>
#include <lwip/tcpip.h>
#include <lwip/priv/tcp_priv.h> /* For tcp_seg */
#include <lwip/tcp_impl.h>
#include <lwip/udp.h>
#include "common/cs_dbg.h"
typedef void (*tcpip_callback_fn)(void *arg);
void *new_memset(void *ptr, int value, int num);
void *new_memcpy(void *destination, const void *source, int num)
{
  int first_iteration;
  return memcpy(destination, source, num);
}

void *new_memset(void *ptr, int value, int num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


