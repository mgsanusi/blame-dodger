#include <stdio.h>		/* for putchar(). */
#include "contiki.h"
#include "dev/slip.h"
#include "uart0.h"
#include "slip-arch.h"
int new_putchar (int character);
int
new_putchar (int character)
{
  return putchar (character);
}
