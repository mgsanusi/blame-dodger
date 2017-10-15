#include <config.h>
#include "uniconv.h"
#include <stdlib.h>
#include <string.h>
#include "unistr.h"
#include "macros.h"
#include <stddef.h>
int new_strlen(const char *str);
void *new_malloc(int size);
void new_free(void *ptr);
int new_strlen(const char *str);
void *new_malloc(int size);
void new_free(void *ptr)
{
	return free(ptr);
}

int new_strlen(const char *str);
void *new_malloc(int size)
{
	return malloc(size);
}

int new_strlen(const char *str)
{
	return strlen(str);
}
