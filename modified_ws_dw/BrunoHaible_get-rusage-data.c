#include <config.h>
#include "resource-ext.h"
#include <errno.h>		/* errno */
#include <stdlib.h>		/* size_t, abort, malloc, free, sbrk */
#include <fcntl.h>		/* open, O_RDONLY */
#include <unistd.h>		/* getpagesize, read, close */
#include <sys/time.h>
#include <sys/resource.h>	/* getrlimit, setrlimit */
#include <sys/utsname.h>
#include <string.h>		/* strlen, strcmp */
#include "vma-iter.h"
#include <stdio.h>

