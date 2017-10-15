#include <config.h>
#include "closein.h"
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "gettext.h"
#include "close-stream.h"
#include "closeout.h"
#include "error.h"
#include "exitfail.h"
#include "freadahead.h"
#include "quotearg.h"

