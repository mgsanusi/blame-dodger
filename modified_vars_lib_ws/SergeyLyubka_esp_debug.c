#include "fw/src/mgos_debug_hal.h"
#include <stdio.h>
#include <stddef.h>
#include <lwip/pbuf.h>
#include <lwip/tcpip.h>
#include <lwip/udp.h>
#include "common/cs_dbg.h"
#include "common/mbuf.h"
#include "fw/src/mgos_features.h"
#include "fw/src/mgos_hal.h"
#include "fw/src/mgos_init.h"
#include "fw/platforms/esp8266/src/esp_exc.h"
void *new_memcpy(void *destination, const void *source, size_t num);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	return memcpy(destination, source, num);
}
