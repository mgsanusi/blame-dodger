#include <config.h>
#include "stat-time.h"
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include "macros.h"


time_t new_time(time_t *timer) {
  return time(timer);
}