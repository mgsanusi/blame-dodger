#include "net/rpl/rpl-conf.h"
#include "net/ip/uip.h"
#include "net/ip/tcpip.h"
#include "net/ipv6/uip-ds6.h"
#include "net/ipv6/uip-icmp6.h"
#include "net/rpl/rpl-private.h"
#include "net/rpl/rpl-ns.h"
#include "lib/list.h"
#include "lib/memb.h"
#include "net/ip/uip-debug.h"
#include <limits.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>
void * new_memcpy(void *destination, const void *source, size_t num);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num);



void * new_memcpy(void *destination, const void *source, size_t num);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num) {
  return memcmp(ptr1, ptr2, num);
}
void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}