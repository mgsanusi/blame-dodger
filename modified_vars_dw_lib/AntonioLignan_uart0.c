#include <stdlib.h>
#include "contiki.h"
#include "sys/energest.h"
#include "dev/uart0.h"
#include "dev/watchdog.h"
#include "lib/ringbuf.h"
#include "isr_compat.h"
int new_putchar(int character);



int new_putchar(int character) {
  return putchar(character);
}