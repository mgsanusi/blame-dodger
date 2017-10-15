#include <config.h>
#include "localcharset.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
void *new_malloc(size_t size);
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num);
void *new_realloc(void *ptr, size_t size);
void new_free(void *ptr);
size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
void *new_malloc(size_t size);
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num);
void *new_realloc(void *ptr, size_t size);
void new_free(void *ptr)
{
    return free(ptr);
}

size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
void *new_malloc(size_t size);
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num);
void *new_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
void *new_malloc(size_t size);
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num)
{
    return memcpy(destination, source, num);
}

size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
void *new_malloc(size_t size);
char *new_strcpy(char *destination, const char *source)
{
    return strcpy(destination, source);
}

size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
char *new_strchr(char *str, int character);
void *new_malloc(size_t size)
{
    return malloc(size);
}

size_t new_strlen(const char *str)
{
    return strlen(str);
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
