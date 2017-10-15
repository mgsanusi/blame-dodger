#include "lwip/opt.h"
#include "lwip/timers.h"
#include "lwip/tcp_impl.h"
#include "lwip/def.h"
#include "lwip/memp.h"
#include "lwip/tcpip.h"
#include "lwip/ip_frag.h"
#include "netif/etharp.h"
#include "lwip/dhcp.h"
#include "lwip/autoip.h"
#include "lwip/igmp.h"
#include "lwip/dns.h"
#include "lwip/sys.h"
#include "lwip/pbuf.h"
time_t
new_time (time_t * timer)
{
  return time (timer);
}
