#include <config.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include "stdio--.h"
#include "xalloc.h"
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_isspace(int c);
int new_puts(const char *str);
void new_exit(int status);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_isspace(int c);
int new_puts(const char *str);
void new_exit(int status)
{
    return exit(status);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_isspace(int c);
int new_puts(const char *str)
{
    return puts(str);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_isspace(int c)
{
    return isspace(c);
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
