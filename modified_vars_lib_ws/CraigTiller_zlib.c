#include <stdlib.h>
#include <zlib.h>
int Main()
{
	deflateInit(Z_NULL, Z_DEFAULT_COMPRESSION);
	return 0;
}
