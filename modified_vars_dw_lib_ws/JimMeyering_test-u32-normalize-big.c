#include <config.h>
#include "test-u32-normalize-big.h"
#include <stdio.h>
#include <stdlib.h>
#include "xalloc.h"
#include "unistr.h"
#include "macros.h"
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status)
{
	return exit(status);
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
