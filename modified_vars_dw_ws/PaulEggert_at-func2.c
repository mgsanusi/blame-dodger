#include <config.h>
#include "openat-priv.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dosname.h"		/* solely for definition of IS_ABSOLUTE_FILE_NAME */
#include "filenamecat.h"
#include "openat.h"
#include "same-inode.h"
#include "save-cwd.h"
