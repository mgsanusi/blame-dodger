#include "net/netstack.h"
#include "net/ip/uip.h"
#include "net/ip/tcpip.h"
#include "net/packetbuf.h"
#include "net/uip-driver.h"
#include <string.h>
#include <stddef.h>
void *new_memcpy (void *destination, const void *source, size_t num);
void *
new_memcpy (void *destination, const void *source, size_t num)
{
  return memcpy (destination, source, num);
}
