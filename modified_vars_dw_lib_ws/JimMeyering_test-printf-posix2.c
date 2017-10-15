#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <errno.h>
void *new_malloc(int size);
int new_atoi(const char *str);
void *new_malloc(int size);
int new_atoi(const char *str)
{
	return atoi(str);
}

void *new_malloc(int size)
{
	return malloc(size);
}
