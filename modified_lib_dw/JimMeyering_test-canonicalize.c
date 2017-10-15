#include <config.h>
#include "canonicalize.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "same-inode.h"
#include "ignore-value.h"
#include "macros.h"

