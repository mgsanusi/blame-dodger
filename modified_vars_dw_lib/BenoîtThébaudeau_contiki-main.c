#include "contiki.h"

#include <stddef.h>
#include "dev/leds.h"
#include "dev/sys-ctrl.h"
#include "dev/nvic.h"
#include "dev/uart.h"
#include "dev/watchdog.h"
#include "dev/ioc.h"
#include "dev/button-sensor.h"
#include "dev/serial-line.h"
#include "dev/slip.h"
#include "dev/cc2538-rf.h"
#include "dev/udma.h"
#include "dev/crypto.h"
#include "dev/rtcc.h"
#include "usb/usb-serial.h"
#include "lib/random.h"
#include "net/netstack.h"
#include "net/queuebuf.h"
#include "net/ip/tcpip.h"
#include "net/ip/uip.h"
#include "net/mac/frame802154.h"
#include "soc.h"
#include "cpu.h"
#include "reg.h"
#include "ieee-addr.h"
#include "lpm.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int new_puts(const char *str);

void * new_memcpy(void *destination, const void *source, int num);



int new_puts(const char *str);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
int new_puts(const char *str) {
  return puts(str);
}