#include <config.h>
#include "copy-file.h"
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "error.h"
#include "safe-read.h"
#include "full-write.h"
#include "acl.h"
#include "binary-io.h"
#include "gettext.h"
#include "xalloc.h"

