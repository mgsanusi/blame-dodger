#include "lwip/opt.h"
#include "lwip/mem.h"
#include "lwip/udp.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"
#include "lwip/autoip.h"
#include "netif/etharp.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
void *new_memset(void *ptr, int value, int num);
void *new_memset(void *ptr, int value, int num)
{
    return memset(ptr, value, num);
}
