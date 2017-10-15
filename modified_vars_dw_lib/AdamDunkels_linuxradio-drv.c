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
void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

int new_read(int fd, void *buf, int count);

char * new_strncpy(char *destination, const char* source, int num);



void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

int new_read(int fd, void *buf, int count);

char * new_strncpy(char *destination, const char* source, int num) {
  return strncpy(destination, source, num);
}
void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

int new_read(int fd, void *buf, int count) {
  return read(fd, buf, count);
}
void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
void* new_malloc(int size) {
  return malloc(size);
}