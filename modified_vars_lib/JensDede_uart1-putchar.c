#include "dev/uart1.h"
int new_putchar(int character);



int new_putchar(int character) {
  return putchar(character);
}