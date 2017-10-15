#include <stdlib.h>
#include <cc65.h>
#include "sys/log.h"
#include "lib/error.h"
void new_exit(int status);
void new_exit(int status)
{
    return exit(status);
}
