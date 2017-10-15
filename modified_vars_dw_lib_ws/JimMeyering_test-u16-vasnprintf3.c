#include <config.h>
#include "unistdio.h"
#include <locale.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "unistr.h"
#include "macros.h"
void new_free(void *ptr);
void new_free(void *ptr)
{
    return free(ptr);
}
