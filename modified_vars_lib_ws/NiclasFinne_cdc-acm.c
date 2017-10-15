#include "cdc-acm.h"
#include "cdc.h"
#include <stddef.h>
#include "usb-api.h"
#include "usb-core.h"
#include <stdio.h>
#include <string.h>
void *new_memcpy(void *destination, const void *source, size_t num);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	return memcpy(destination, source, num);
}
