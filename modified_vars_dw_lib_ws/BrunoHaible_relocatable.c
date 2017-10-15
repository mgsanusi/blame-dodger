#include <config.h>
#include "relocatable.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
istream & new_getline(istream & is, string & str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str);
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num);
void new_free(void *ptr);
int new_strncmp(const char *str1, const char *str2, int num);
istream & new_getline(istream & is, string & str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str);
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num);
void new_free(void *ptr);
int new_strncmp(const char *str1, const char *str2, int num)
{
	return strncmp(str1, str2, num);
}

istream & new_getline(istream & is, string & str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str);
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num);
void new_free(void *ptr)
{
	return free(ptr);
}

istream & new_getline(istream & is, string & str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str);
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
}

istream & new_getline(istream & is, string & str)
{
	return getline(is, str);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str);
char *new_strcpy(char *destination, const char *source)
{
	return strcpy(destination, source);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str)
{
	return strlen(str);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character)
{
	return strchr(str, character);
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
