#include <config.h>
#include "yesno.h"
#include <stdlib.h>
#include <stdio.h>
istream & new_getline(istream & is, string & str)
{
	return getline(is, str);
}

int new_getchar();
int new_getchar()
{
	return getchar();
}
