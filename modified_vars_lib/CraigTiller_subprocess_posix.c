#include <grpc/support/port_platform.h>
#include <grpc/support/subprocess.h>
#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
void * new_memcpy(void *destination, const void *source, size_t num);

char * new_strerror(int errnum);



void * new_memcpy(void *destination, const void *source, size_t num);

char * new_strerror(int errnum) {
  return strerror(errnum);
}
void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}