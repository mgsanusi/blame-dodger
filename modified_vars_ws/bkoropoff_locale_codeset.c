#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <langinfo.h>
int Main()
{
	setlocale(LC_ALL, "");
	printf("%s\n", nl_langinfo(CODESET));
	exit(0);
}
