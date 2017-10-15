#include <stdio.h>
#include <debug-uart.h>
#include <string.h>
int new_puts(const char *str);
int new_puts(const char *str)
{
	return puts(str);
}
