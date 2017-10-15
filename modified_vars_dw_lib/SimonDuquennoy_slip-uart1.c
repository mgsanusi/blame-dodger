#include "contiki.h"
#include "dev/slip.h"
#include "mc1322x.h"
int new_putchar(int character);



int new_putchar(int character) {
  return putchar(character);
}