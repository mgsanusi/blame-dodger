#include <string.h>

#include <stddef.h>
#include "net/ip/uip-split.h"
#include "net/ip/uip.h"
#include "net/ipv4/uip-fw.h"
#include "net/ip/uip_arch.h"
#include "net/ip/tcpip.h"
void * new_memcpy(void *destination, const void *source, size_t num);



void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}