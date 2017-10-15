#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/time.h>
#include "common/platforms/esp8266/esp_missing_includes.h"
#include "common/umm_malloc/umm_malloc.h"
#include "esp_system.h"
#include "user_interface.h"
#include "fw/src/mgos_hal.h"
#include "fw/platforms/esp8266/src/esp_features.h"
void *new_calloc(int num, int size);
void *new_malloc(int size);
void *new_realloc(void *ptr, int size);
void new_free(void *ptr);
void *new_calloc(int num, int size);
void *new_malloc(int size);
void *new_realloc(void *ptr, int size);
void new_free(void *ptr)
{
	return free(ptr);
}

void *new_calloc(int num, int size);
void *new_malloc(int size);
void *new_realloc(void *ptr, int size)
{
	return realloc(ptr, size);
}

void *new_calloc(int num, int size);
void *new_malloc(int size)
{
	return malloc(size);
}

void *new_calloc(int num, int size)
{
	return calloc(num, size);
}
