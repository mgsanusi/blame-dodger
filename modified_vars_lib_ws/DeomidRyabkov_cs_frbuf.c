#include "common/cs_frbuf.h"
#include "common/cs_dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_malloc(size_t size);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_malloc(size_t size)
{
	return malloc(size);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}
