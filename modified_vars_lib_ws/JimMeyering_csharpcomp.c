#include <config.h>
#include <alloca.h>
#include "csharpcomp.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "execute.h"
#include <stddef.h>
#include <stddef.h>
#include "spawn-pipe.h"
#include "wait-process.h"
#include "sh-quote.h"
#include "safe-read.h"
#include "xmalloca.h"
#include "error.h"
#include "gettext.h"
istream & new_getline(istream & is, string & str);
size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
char *new_strcpy(char *destination, const char *source);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
istream & new_getline(istream & is, string & str);
size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
char *new_strcpy(char *destination, const char *source);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    return memcmp(ptr1, ptr2, num);
}

istream & new_getline(istream & is, string & str);
size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
char *new_strcpy(char *destination, const char *source);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr)
{
    return free(ptr);
}

istream & new_getline(istream & is, string & str);
size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
char *new_strcpy(char *destination, const char *source);
void *new_memcpy(void *destination, const void *source, size_t num)
{
    return memcpy(destination, source, num);
}

istream & new_getline(istream & is, string & str)
{
    return getline(is, str);
}

size_t new_strlen(const char *str);
int new_fclose(FILE * stream);
char *new_strcpy(char *destination, const char *source)
{
    return strcpy(destination, source);
}

size_t new_strlen(const char *str)
{
    return strlen(str);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
