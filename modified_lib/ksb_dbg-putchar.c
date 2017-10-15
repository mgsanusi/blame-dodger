#include <stdio.h>
#include <debug-uart.h>
#include <string.h>

#undef putchar
#undef putc
int new_putchar(int character);


int
new_putchar(int c)
{
  dbg_new_putchar(c);
  return c;
}

int
putc(int c, FILE *f)
{
  dbg_new_putchar(c);
  return c;
}

int
__sp(struct _reent *_ptr, int c, FILE *_p) {
  dbg_new_putchar(c);
  return c;
}

int new_putchar(int character) {
  return putchar(character);
}