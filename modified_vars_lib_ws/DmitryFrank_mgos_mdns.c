#include "fw/src/mgos_mdns.h"
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>
#include "common/platform.h"
#include "common/cs_dbg.h"
#include "common/queue.h"
#include "fw/src/mgos_mongoose.h"
#include "fw/src/mgos_sys_config.h"
#include "fw/src/mgos_wifi.h"
void *new_calloc (size_t num, size_t size);
void *
new_calloc (size_t num, size_t size)
{
  return calloc (num, size);
}
