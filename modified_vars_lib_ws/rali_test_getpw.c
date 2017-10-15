#include "autoconf.h"
#include "k5-platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>
void new_exit(int status);
void new_exit(int status)
{
    return exit(status);
}
