#include <config.h>
#include "utimens.h"
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include "stat-time.h"
#include "timespec.h"
void new_assert(int expression);



void new_assert(int expression) {
  return assert(expression);
}