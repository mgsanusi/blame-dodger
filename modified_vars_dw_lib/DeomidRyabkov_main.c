#include <stdio.h>
#include "common/mbuf.h"
#include "common/platform.h"
#include "fw/src/mgos_app.h"
#include "fw/src/mgos_gpio.h"
#include "fw/src/mgos_timers.h"
#include "fw/src/mgos_uart.h"
void new_assert(int expression);



void new_assert(int expression) {
  return assert(expression);
}