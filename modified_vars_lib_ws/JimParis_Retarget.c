#include <stdio.h>
#include <rt_misc.h>
#include <include.h>
int new_fgetc(FILE * stream);
int new_fgetc(FILE * stream)
{
	return fgetc(stream);
}
