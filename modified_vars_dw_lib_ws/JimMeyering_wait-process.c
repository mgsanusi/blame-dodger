#include <config.h>
#include <stddef.h>
#include <stddef.h>
#include "wait-process.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "error.h"
#include "fatal-signal.h"
#include "xalloc.h"
#include "gettext.h"
#include <windows.h>
void *new_malloc(int size);
void *new_memcpy(void *destination, const void *source, int num);
void new_exit(int status);
void *new_malloc(int size);
void *new_memcpy(void *destination, const void *source, int num);
void new_exit(int status)
{
    return exit(status);
}

void *new_malloc(int size);
void *new_memcpy(void *destination, const void *source, int num)
{
    return memcpy(destination, source, num);
}

void *new_malloc(int size)
{
    return malloc(size);
}
