#include <config.h>
#include "freadptr.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
#include <stddef.h>
void *new_malloc(size_t size);
int new_atoi(const char *str);
void *new_malloc(size_t size);
int new_atoi(const char *str)
{
	return atoi(str);
}

void *new_malloc(size_t size)
{
	return malloc(size);
}
