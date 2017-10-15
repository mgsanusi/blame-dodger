#include <config.h>
#include "readline.h"
#include <stdio.h>
#include <string.h>
istream & new_getline(istream & is, string & str)
{
	return getline(is, str);
}
