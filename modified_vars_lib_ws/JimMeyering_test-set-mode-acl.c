#include <config.h>
#include "acl.h"
#include <stdlib.h>
#include "progname.h"
#include "macros.h"
long
long int new_strtol(const char *str, char **endptr, int base);
int new_strtol(const char *str, char **endptr, int base)
{
	return strtol(str, endptr, base);
}
