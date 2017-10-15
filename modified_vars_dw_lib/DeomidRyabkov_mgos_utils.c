#include <stdlib.h>
#include "common/cs_dbg.h"
#include "fw/src/mgos_hal.h"
#include "fw/src/mgos_timers.h"
int new_rand();



int new_rand() {
  return rand();
}