#include "fw/platforms/esp8266/src/esp_features.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "umm_malloc_cfg.h"

#include <stddef.h>
#include "fw/src/mgos_debug.h"
#include "fw/src/mgos_uart.h"
#include "fw/platforms/esp8266/src/esp_exc.h"
typedef uint8_t item_type_t;
void* new_realloc(void *ptr, int size);



void* new_realloc(void *ptr, int size) {
  return realloc(ptr, size);
}