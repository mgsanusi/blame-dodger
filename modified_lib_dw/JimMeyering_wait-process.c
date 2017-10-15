#include <config.h>
#include <stddef.h>
#include <stddef.h>
#include "wait-process.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "error.h"
#include "fatal-signal.h"
#include "xalloc.h"
#include "gettext.h"
#include <windows.h>

