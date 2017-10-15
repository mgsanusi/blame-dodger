#include <config.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include "xalloc.h"
void new_exit(int status);
int new_atoi(const char *str);
void new_free(void *ptr);
void new_exit(int status);
int new_atoi(const char *str);
void new_free(void *ptr)
{
    return free(ptr);
}

void new_exit(int status);
int new_atoi(const char *str)
{
    return atoi(str);
}

void new_exit(int status)
{
    return exit(status);
}
