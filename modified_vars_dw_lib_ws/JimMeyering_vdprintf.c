#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include "full-write.h"
#include "vasnprintf.h"
void new_free(void *ptr);
void new_free(void *ptr)
{
    return free(ptr);
}
