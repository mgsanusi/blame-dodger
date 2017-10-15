#include <stdlib.h>
long long
long long int new_strtoll(const char *str, char **endptr, int base);
int new_strtoll(const char *str, char **endptr, int base)
{
    return strtoll(str, endptr, base);
}
