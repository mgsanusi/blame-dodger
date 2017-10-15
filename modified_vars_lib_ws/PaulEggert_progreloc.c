#include <config.h>
#include "progname.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/stat.h>
#include "relocatable.h"
size_t new_strlen(const char *str);
char *new_strchr(char *str, int character);
char *new_strcpy(char *destination, const char *source);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
size_t new_strlen(const char *str);
char *new_strchr(char *str, int character);
char *new_strcpy(char *destination, const char *source);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    return memcmp(ptr1, ptr2, num);
}

size_t new_strlen(const char *str);
char *new_strchr(char *str, int character);
char *new_strcpy(char *destination, const char *source);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr)
{
    return free(ptr);
}

size_t new_strlen(const char *str);
char *new_strchr(char *str, int character);
char *new_strcpy(char *destination, const char *source);
void *new_memcpy(void *destination, const void *source, size_t num)
{
    return memcpy(destination, source, num);
}

size_t new_strlen(const char *str);
char *new_strchr(char *str, int character);
char *new_strcpy(char *destination, const char *source)
{
    return strcpy(destination, source);
}

size_t new_strlen(const char *str)
{
    return strlen(str);
}

char *new_strchr(char *str, int character)
{
    return strchr(str, character);
}
