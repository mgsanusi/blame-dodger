#include <config.h>
#include "pipe-filter.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "full-write.h"
#include "progname.h"
#include "macros.h"
size_t new_strlen(const char *str)
{
	return strlen(str);
}
