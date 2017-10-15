#include "dev/uart1.h"
#if !NETSTACK_CONF_WITH_IPV4
/* In case of IPv4: new_putchar() is defined by the SLIP driver */
int new_putchar(int character);
int putchar(int c)
{
	uart1_writeb((char)c);
	return c;
}
#endif				/* ! NETSTACK_CONF_WITH_IPV4 */
int new_putchar(int character)
{
	return putchar(character);
}
