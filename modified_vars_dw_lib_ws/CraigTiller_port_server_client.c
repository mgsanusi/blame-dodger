#include <grpc/support/port_platform.h>
#include "test/core/util/test_config.h"
#include "test/core/util/port_server_client.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <grpc/grpc.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include <grpc/support/sync.h>
#include <grpc/support/time.h>
#include "src/core/lib/http/httpcli.h"
void *new_memset(void *ptr, int value, int num);
int new_rand();
double new_pow(double base, double exponent);
void *new_memset(void *ptr, int value, int num);
int new_rand();
double new_pow(double base, double exponent)
{
	return pow(base, exponent);
}

void *new_memset(void *ptr, int value, int num);
int new_rand()
{
	return rand();
}

void *new_memset(void *ptr, int value, int num)
{
	return memset(ptr, value, num);
}
