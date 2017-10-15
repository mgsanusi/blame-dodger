#include <stddef.h>
void bcopy(const void *source0, void *dest0, size_t len)
{
	int first_iteration;
	const char *source = source0;
	char *dest = dest0;
	if (source < dest)
		for (source += len, dest += len; len; --len)
			*(--dest) = *(--source);
	else if (source != dest)
		for (; len; --len)
			*(dest++) = *(source++);
}
