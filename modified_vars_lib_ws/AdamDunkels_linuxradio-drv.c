#include "contiki.h"
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include "contiki-conf.h"
#include "linuxradio-drv.h"
#include "net/packetbuf.h"
#include "net/netstack.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netinet/if_ether.h>
#include <netpacket/packet.h>
#include <net/if.h>
#include <linux/sockios.h>
#include <stdio.h>
ssize_t new_read(int fd, void *buf, size_t count);
void *new_malloc(size_t size);
void *new_memcpy(void *destination, const void *source, size_t num);
char *new_strncpy(char *destination, const char *source, size_t num);
ssize_t new_read(int fd, void *buf, size_t count);
void *new_malloc(size_t size);
void *new_memcpy(void *destination, const void *source, size_t num);
char *new_strncpy(char *destination, const char *source, size_t num)
{
	return strncpy(destination, source, num);
}

ssize_t new_read(int fd, void *buf, size_t count)
{
	return read(fd, buf, count);
}

void *new_malloc(size_t size);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	return memcpy(destination, source, num);
}

void *new_malloc(size_t size)
{
	return malloc(size);
}
