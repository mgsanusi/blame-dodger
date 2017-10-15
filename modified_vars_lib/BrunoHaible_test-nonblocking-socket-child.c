#include <config.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include "nonblocking.h"
#include "macros.h"
#include "socket-client.h"
#include "test-nonblocking-socket.h"
#include "test-nonblocking-reader.h"
int new_atoi(const char *str);



int new_atoi(const char *str) {
  return atoi(str);
}