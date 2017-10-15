#include <string.h>
#include "dev/uart0.h"
int new_putchar(int character);
int new_puts(const char *str);
int new_putchar(int character);
int new_puts(const char *str)
{
	return puts(str);
}

int new_putchar(int character)
{
	return putchar(character);
}
