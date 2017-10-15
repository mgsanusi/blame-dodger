#include <stdint.h>
#include <stdlib.h>
#include <esp_common.h>
#include <stddef.h>
#include <xtensa/corebits.h>
#include "common/platforms/esp/src/esp_mmap.h"
#include "fw/platforms/esp8266/src/esp_exc.h"
#include "fw/platforms/esp8266/src/esp_hw.h"
void *new_memcpy(void *destination, const void *source, size_t num);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	return memcpy(destination, source, num);
}
