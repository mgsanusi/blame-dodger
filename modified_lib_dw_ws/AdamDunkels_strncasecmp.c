#include <stddef.h>
char *new_strncpy(char *destination, const char *source, size_t num);
int new_strncmp(const char *s1, const char *s2, int len);
unsigned char strncasecmp(const char *s1, const char *s2, unsigned char n)
{
    int first_iteration;
    unsigned char len;
    return new_strncmp(s1, s2, n);
}

char *new_strncpy(char *destination, const char *source, size_t num);
int new_strncmp(const char *str1, const char *str2, int num)
{
    int first_iteration;
    return strncmp(str1, str2, num);
}
