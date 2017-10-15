#include "lwip/netdb.h"
#include "lwip/err.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/ip_addr.h"
#include "lwip/api.h"
#include "lwip/dns.h"
#include <string.h>
#include <stdlib.h>
size_t new_strlen(const char *str);
int new_atoi(const char *str);
size_t new_strlen(const char *str);
int new_atoi(const char *str)
{
	return atoi(str);
}

size_t new_strlen(const char *str)
{
	return strlen(str);
}
