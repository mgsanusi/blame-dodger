#include <config.h>
#include <stddef.h>
#include "sigpipe-die.h"
#include <signal.h>
#include <stdlib.h>
#include "error.h"
#include "exitfail.h"
#include "gettext.h"
void *new_malloc(size_t size);
void new_exit(int status);
void *new_malloc(size_t size);
void new_exit(int status)
{
	return exit(status);
}

void *new_malloc(size_t size)
{
	return malloc(size);
}
