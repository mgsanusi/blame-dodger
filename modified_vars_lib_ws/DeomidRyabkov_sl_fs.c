#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include "common/cs_dbg.h"
#include "common/platform.h"
#include "cc3200_fs_spiffs.h"
#include "sl_fs_slfs.h"
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <driverlib/rom.h>
#include <driverlib/rom_map.h>
#include <driverlib/uart.h>
ssize_t new_read(int fd, void *buf, size_t count);
void *new_memset(void *ptr, int value, size_t num);
char *new_strchr(char *str, int character);
int new_strncmp(const char *str1, const char *str2, size_t num);
ssize_t new_read(int fd, void *buf, size_t count);
void *new_memset(void *ptr, int value, size_t num);
char *new_strchr(char *str, int character);
int new_strncmp(const char *str1, const char *str2, size_t num)
{
    return strncmp(str1, str2, num);
}

ssize_t new_read(int fd, void *buf, size_t count)
{
    return read(fd, buf, count);
}

void *new_memset(void *ptr, int value, size_t num);
char *new_strchr(char *str, int character)
{
    return strchr(str, character);
}

void *new_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}
