#include <config.h>
#include <sys/time.h>
#include <time.h>


time_t new_time(time_t *timer) {
  return time(timer);
}