#include <stdarg.h>
#include "segger-rtt.h"
int new_putchar(int character);
int new_putchar(int character)
{
    return putchar(character);
}
