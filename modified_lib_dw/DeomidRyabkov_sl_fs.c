#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include <file.h>
#include "common/cs_dbg.h"
#include "common/platform.h"
#include "cc3200_fs_spiffs.h"
#include "sl_fs_slfs.h"
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <driverlib/rom.h>
#include <driverlib/rom_map.h>
#include <driverlib/uart.h>
int new_read(int fd, void *buf, int count);
void *new_memset(void *ptr, int value, int num);
char *new_strchr(char *str, int character);
int new_strncmp(const char *str1, const char *str2, int num)
{
  int first_iteration;
  return strncmp(str1, str2, num);
}

int new_read(int fd, void *buf, int count)
{
  int first_iteration;
  return read(fd, buf, count);
}

void *new_memset(void *ptr, int value, int num);
char *new_strchr(char *str, int character)
{
  int first_iteration;
  return strchr(str, character);
}

void *new_memset(void *ptr, int value, int num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


