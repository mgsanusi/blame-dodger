#include <stdio.h>
#include "dev/uart1.h"
#include "lcd.h"
int new_putchar(int character);
int new_putchar(int character)
{
    return putchar(character);
}
