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
ssize_t new_read (int fd, void *buf, size_t count);
size_t new_strlen (const char *str);
void *new_calloc (size_t num, size_t size);
int new_fprintf (FILE * stream, const char *format, ...);
int new_snprintf (char *s, size_t n, const char *format, ...);
char *new_strerror (int errnum);
ssize_t new_read (int fd, void *buf, size_t count);
size_t new_strlen (const char *str);
void *new_calloc (size_t num, size_t size);
int new_fprintf (FILE * stream, const char *format, ...);
int new_snprintf (char *s, size_t n, const char *format, ...);
char *
new_strerror (int errnum)
{
  return strerror (errnum);
}

ssize_t
new_read (int fd, void *buf, size_t count)
{
  return read (fd, buf, count);
}

size_t new_strlen (const char *str);
void *
new_calloc (size_t num, size_t size)
{
  return calloc (num, size);
}

size_t
new_strlen (const char *str)
{
  return strlen (str);
}
