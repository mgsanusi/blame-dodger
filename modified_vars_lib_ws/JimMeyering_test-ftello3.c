#include <config.h>
#include <stdio.h>
#include <string.h>
#include "macros.h"
#include <stddef.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	return memcmp(ptr1, ptr2, num);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream);
int new_getc(FILE * stream)
{
	return getc(stream);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}
