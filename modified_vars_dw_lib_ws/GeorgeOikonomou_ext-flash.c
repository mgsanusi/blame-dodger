#include "contiki.h"
#include "ext-flash.h"
#include "ti-lib.h"
#include "board-spi.h"
#include <stdint.h>
#include <stdbool.h>
time_t new_time(time_t * timer)
{
    return time(timer);
}
