#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
void *new_memcpy(void *destination, const void *source, int num);
void *new_memcpy(void *destination, const void *source, int num)
{
    return memcpy(destination, source, num);
}
