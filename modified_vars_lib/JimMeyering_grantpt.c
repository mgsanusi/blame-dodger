#include <config.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "configmake.h"
#include "pty-private.h"
void new_assert(int expression);



void new_assert(int expression) {
  return assert(expression);
}