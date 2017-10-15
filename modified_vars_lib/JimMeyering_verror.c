#include <config.h>
#include "verror.h"
#include "xvasprintf.h"
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
char * new_strerror(int errnum);



char * new_strerror(int errnum) {
  return strerror(errnum);
}