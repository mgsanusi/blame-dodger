#include <config.h>
#include "read-file.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int new_fprintf(FILE * stream, const char *format, ...);
void new_free(void *ptr);
int new_fprintf(FILE * stream, const char *format, ...);
void new_free(void *ptr)
{
	return free(ptr);
}
