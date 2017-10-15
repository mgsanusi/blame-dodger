#include <config.h>
#include "savewd.h"
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "dosname.h"
#include "fcntl-safer.h"
void new_assert(int expression);



void new_assert(int expression) {
  return assert(expression);
}