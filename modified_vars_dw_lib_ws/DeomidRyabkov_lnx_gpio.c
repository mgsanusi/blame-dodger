#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <poll.h>
#include "fw/src/mgos_gpio.h"
#include "fw/src/mgos_gpio_hal.h"
int new_strlen (const char *str);
void *new_calloc (int num, int size);
int new_fprintf (FILE * stream, const char *format, ...);
int new_snprintf (char *s, int n, const char *format, ...);
int new_read (int fd, void *buf, int count);
char *new_strerror (int errnum);
int new_strlen (const char *str);
void *new_calloc (int num, int size);
int new_fprintf (FILE * stream, const char *format, ...);
int new_snprintf (char *s, int n, const char *format, ...);
int new_read (int fd, void *buf, int count);
char *
new_strerror (int errnum)
{
  return strerror (errnum);
}

int new_strlen (const char *str);
void *new_calloc (int num, int size);
int new_fprintf (FILE * stream, const char *format, ...);
int new_snprintf (char *s, int n, const char *format, ...);
int
new_read (int fd, void *buf, int count)
{
  return read (fd, buf, count);
}

int new_strlen (const char *str);
void *
new_calloc (int num, int size)
{
  return calloc (num, size);
}

int
new_strlen (const char *str)
{
  return strlen (str);
}
