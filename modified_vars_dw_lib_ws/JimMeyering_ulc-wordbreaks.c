#include <config.h>
#include "uniwbrk.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include "c-ctype.h"
#include "localcharset.h"
#include "uniconv.h"
#include "unilbrk/ulc-common.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
void *new_memset(void *ptr, int value, int num);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
void *new_realloc(void *ptr, int size);
void new_free(void *ptr);
void *new_memset(void *ptr, int value, int num);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
void *new_realloc(void *ptr, int size);
void new_free(void *ptr)
{
	return free(ptr);
}

void *new_memset(void *ptr, int value, int num);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
void *new_realloc(void *ptr, int size)
{
	return realloc(ptr, size);
}

void *new_memset(void *ptr, int value, int num);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status)
{
	return exit(status);
}

void *new_memset(void *ptr, int value, int num);
void *new_malloc(int size)
{
	return malloc(size);
}

void *new_memset(void *ptr, int value, int num)
{
	return memset(ptr, value, num);
}
