#include <config.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void new_exit(int status);
void new_exit(int status)
{
    return exit(status);
}
