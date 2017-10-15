#include <config.h>
#include <alloca.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "malloca.h"
#include <bits/libc-lock.h>
#include <search.h>
typedef int (*compar_fn_t) (const void *, const void *);

