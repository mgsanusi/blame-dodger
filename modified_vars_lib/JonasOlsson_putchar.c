#include "cc26xx-uart.h"
#include "ti-lib.h"
#include <string.h>
int new_putchar(int character);

int new_puts(const char *str);



int new_putchar(int character);

int new_puts(const char *str) {
  return puts(str);
}
int new_putchar(int character) {
  return putchar(character);
}