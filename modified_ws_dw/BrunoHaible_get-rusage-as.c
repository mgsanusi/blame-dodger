#include <config.h>
#include "resource-ext.h"
#include <errno.h>		/* errno */
#include <stdlib.h>		/* size_t, abort */
#include <fcntl.h>		/* open, O_RDONLY */
#include <unistd.h>		/* getpagesize, read, close */
#include <sys/time.h>
#include <sys/resource.h>	/* getrlimit, setrlimit */
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>		/* mmap, munmap */
#include "vma-iter.h"
#include <stdio.h>

