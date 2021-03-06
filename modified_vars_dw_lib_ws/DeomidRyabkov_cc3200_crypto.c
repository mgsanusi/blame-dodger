#include "fw/platforms/cc3200/src/cc3200_crypto.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FreeRTOS.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_shamd5.h"
#include "rom.h"
#include "rom_map.h"
#include <stddef.h>
#include "driverlib/prcm.h"
#include "driverlib/shamd5.h"
#include "common/cs_dbg.h"
int new_strlen(const char *str);
void *new_memcpy(void *destination, const void *source, int num);
int new_strlen(const char *str);
void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
}

int new_strlen(const char *str)
{
	return strlen(str);
}
