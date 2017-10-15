#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xalloc.h"
#include "uniname.h"
#include "progname.h"
#include <stddef.h>
size_t new_strlen(const char *str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_rand();
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_exit(int status);
size_t new_strlen(const char *str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_rand();
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_exit(int status)
{
	return exit(status);
}

size_t new_strlen(const char *str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_rand();
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	return memcpy(destination, source, num);
}

size_t new_strlen(const char *str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_rand()
{
	return rand();
}

size_t new_strlen(const char *str)
{
	return strlen(str);
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
