#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xalloc.h"
#include "uniname.h"
#include "progname.h"
#include <stddef.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_strlen(const char *str);
int new_rand();
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num);
void new_exit(int status);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_strlen(const char *str);
int new_rand();
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num);
void new_exit(int status)
{
	return exit(status);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_strlen(const char *str);
int new_rand();
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_strlen(const char *str);
int new_rand()
{
	return rand();
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_strlen(const char *str)
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
