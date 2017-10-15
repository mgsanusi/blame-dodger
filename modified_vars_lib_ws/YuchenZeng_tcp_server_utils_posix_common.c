#include "src/core/lib/iomgr/port.h"
#include "src/core/lib/iomgr/tcp_server_utils_posix.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include <grpc/support/sync.h>
#include "src/core/lib/iomgr/error.h"
#include "src/core/lib/iomgr/sockaddr.h"
#include "src/core/lib/iomgr/sockaddr_utils.h"
#include "src/core/lib/iomgr/unix_sockets_posix.h"
long long FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
void *new_memcpy (void *destination, const void *source, size_t num);
char *new_fgets (char *str, int num, FILE * stream);
int new_strtol (const char *str, char **endptr, int base);
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
void *new_memcpy (void *destination, const void *source, size_t num);
char *new_fgets (char *str, int num, FILE * stream);
int
new_strtol (const char *str, char **endptr, int base)
{
  return strtol (str, endptr, base);
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
void *new_memcpy (void *destination, const void *source, size_t num);
char *
new_fgets (char *str, int num, FILE * stream)
{
  return fgets (str, num, stream);
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
void *
new_memcpy (void *destination, const void *source, size_t num)
{
  return memcpy (destination, source, num);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

int
new_fclose (FILE * stream)
{
  return fclose (stream);
}
