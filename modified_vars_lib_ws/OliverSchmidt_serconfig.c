#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <serial.h>
#include "cfs/cfs.h"
int new_putchar (int character);
int new_getchar ();
void new_exit (int status);
int new_putchar (int character);
int new_getchar ();
void
new_exit (int status)
{
  return exit (status);
}

int new_putchar (int character);
int
new_getchar ()
{
  return getchar ();
}

int
new_putchar (int character)
{
  return putchar (character);
}
