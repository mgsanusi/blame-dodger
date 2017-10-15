#include <stdio.h>
#include <stdint.h>
#include "nordic_common.h"
#include "nrf_drv_config.h"
#include "nrf_drv_gpiote.h"
#include "softdevice_handler.h"

#include <stddef.h>
#include "ble/ble-core.h"
#include "ble/ble-mac.h"
#include "contiki.h"
#include "contiki-net.h"
#include "leds.h"
#include "lib/sensors.h"
#include "dev/watchdog.h"
#include "dev/serial-line.h"
#include "dev/uart0.h"
#include "dev/lpm.h"
#include "uip-debug.h"
#include "net/ipv6/uip-ds6.h"
#include <stdio.h>
void * new_memcpy(void *destination, const void *source, size_t num);



void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}