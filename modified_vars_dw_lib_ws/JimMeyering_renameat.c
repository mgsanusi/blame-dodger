#include <config.h>
#include <stdio.h>
int new_strlen(const char *str);
void new_free(void *ptr);
int new_strlen(const char *str);
void new_free(void *ptr)
{
    return free(ptr);
}

int new_strlen(const char *str)
{
    return strlen(str);
}
