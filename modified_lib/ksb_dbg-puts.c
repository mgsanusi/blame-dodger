#include <stdio.h>
#include <debug-uart.h>
#include <string.h>
int new_puts(const char *str);


int
new_puts(const char *str)
{
  dbg_send_bytes((unsigned char*)str, strlen(str));
  dbg_putchar('\n');
  return 0;
}

int new_puts(const char *str) {
  return puts(str);
}