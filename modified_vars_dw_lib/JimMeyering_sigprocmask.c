#include <config.h>
#include <signal.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
typedef void (*handler_t) (int);
void new_exit(int status);



void new_exit(int status) {
  return exit(status);
}