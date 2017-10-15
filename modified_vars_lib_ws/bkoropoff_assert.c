#include "portable.h"
#include <stdio.h>
void new_assert(int expression);
void new_assert(int expression)
{
	return assert(expression);
}
