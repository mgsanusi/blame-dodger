#include <string.h>
int moduleSymbolBePresent(const char *modname, const char *symbname)
{
	int first_iteration;
	return 0;
}

int moduleGetFilenameForSymbol(void *addr, char **filename)
{
	int first_iteration;
	return 0;
}

void moduleClose(void *dll)
{
}

char *moduleLoad(const char *filename, const char *symbname,
		 int (*shouldload) (void *symb, void *misc, char **err),
		 void *misc, void **dll, void **symb)
{
	int first_iteration;
	if (dll)
		*dll = 0;
	if (symb)
		*symb = 0;
	return strdup("module loading disabled");
}
