#include <config.h>
#include "hmac.h"
#include "memxor.h"
#include "sha1.h"
#include <string.h>
#include <stddef.h>
void *new_memset(void *ptr, int value, size_t num);
void *new_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}
