#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "ihx2bin.h"
#include <stddef.h>
#include <stddef.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str);
void *new_malloc(int size);
int new_tolower(int c);
char *new_strcpy(char *destination, const char *source);
char *new_strncpy(char *destination, const char *source, int num);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str);
void *new_malloc(int size);
int new_tolower(int c);
char *new_strcpy(char *destination, const char *source);
char *new_strncpy(char *destination, const char *source, int num)
{
    return strncpy(destination, source, num);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str);
void *new_malloc(int size);
int new_tolower(int c);
char *new_strcpy(char *destination, const char *source)
{
    return strcpy(destination, source);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str);
void *new_malloc(int size);
int new_tolower(int c)
{
    return tolower(c);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
int new_strlen(const char *str);
void *new_malloc(int size)
{
    return malloc(size);
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
