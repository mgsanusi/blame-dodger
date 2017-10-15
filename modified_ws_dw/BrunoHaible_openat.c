#include <config.h>
#include <fcntl.h>
#include <sys/types.h>
#include "fcntl.h"
#include "openat.h"
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include "dosname.h"		/* solely for definition of IS_ABSOLUTE_FILE_NAME */
#include "openat-priv.h"
#include "save-cwd.h"

