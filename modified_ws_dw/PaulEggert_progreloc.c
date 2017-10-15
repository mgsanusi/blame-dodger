#include <config.h>
#include "progname.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <mach-o/dyld.h>
#include <windows.h>
#include "relocatable.h"
#include "areadlink.h"
#include "xreadlink.h"
#include "xalloc.h"

