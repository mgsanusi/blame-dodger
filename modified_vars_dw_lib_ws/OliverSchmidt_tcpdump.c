#include "contiki-net.h"
#include <string.h>
#include <stdio.h>
char *new_strcpy(char *destination, const char *source);
char *new_strcpy(char *destination, const char *source)
{
    return strcpy(destination, source);
}
