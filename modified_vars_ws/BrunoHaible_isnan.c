#include <config.h>
#include <float.h>
#include <string.h>
#include "float+.h"
typedef union {
	DOUBLE value;
	unsigned int word[NWORDS];
} memory_double;
