#include "common/mg_mem.h"
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_strlen(const char *str);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_strlen(const char *str);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream)
{
    return fgets(str, num, stream);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_strlen(const char *str);
int new_isspace(int c)
{
    return isspace(c);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_strlen(const char *str)
{
    return strlen(str);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
