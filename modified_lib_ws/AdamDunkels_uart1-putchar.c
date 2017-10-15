#include <stdio.h>
#include "dev/uart1.h"
#include "lcd.h"
int new_putchar (int character);
int
new_putchar (int c)
{
  uart1_writeb ((char) c);
  lcd_write_char ((char) c);
  return c;
}

int
new_putchar (int character)
{
  return putchar (character);
}
