#include <config.h>
#include "xfreopen.h"
#include <errno.h>
#include "error.h"
#include "exitfail.h"
#include "quote.h"
#include "stdio--.h"
#include "gettext.h"
FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
