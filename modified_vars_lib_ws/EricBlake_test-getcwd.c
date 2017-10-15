#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "pathmax.h"
#include "macros.h"
size_t new_strlen(const char *str);
void new_free(void *ptr);
size_t new_strlen(const char *str);
void new_free(void *ptr)
{
	return free(ptr);
}

size_t new_strlen(const char *str)
{
	return strlen(str);
}
