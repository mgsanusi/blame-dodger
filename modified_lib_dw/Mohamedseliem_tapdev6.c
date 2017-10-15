#include "net/ip/uip.h"
#include "net/ip/uipopt.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet6/in6_var.h>
#include <netinet6/nd6.h> // ND6_INFINITE_LIFETIME
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <net/route.h> // AF_ROUTE things
#include "tapdev6.h"
#include "contiki-net.h"

