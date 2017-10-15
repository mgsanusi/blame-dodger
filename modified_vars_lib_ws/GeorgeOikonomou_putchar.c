#include "contiki-conf.h"
#include "dev/io-arch.h"
int new_putchar(int character);
int new_putchar(int character)
{
	return putchar(character);
}
