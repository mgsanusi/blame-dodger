#include <config.h>
#include "xnanosleep.h"
#include <timespec.h>
#include <errno.h>
#include <time.h>


time_t new_time(time_t *timer) {
  return time(timer);
}