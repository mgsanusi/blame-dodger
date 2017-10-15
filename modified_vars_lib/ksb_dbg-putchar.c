#include <stdio.h>
#include <debug-uart.h>
#include <string.h>
int new_putchar(int character);



int new_putchar(int character) {
  return putchar(character);
}