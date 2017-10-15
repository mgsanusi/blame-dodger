#include <config.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
int new_isupper(int c);
int new_tolower(int c);
int new_isupper(int c);
int new_tolower(int c)
{
    return tolower(c);
}

int new_isupper(int c)
{
    return isupper(c);
}
