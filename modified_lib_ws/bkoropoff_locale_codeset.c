/* Prints the system dependent name for the current locale's codeset. */
#define _XOPEN_SOURCE 500	/* Needed on AIX 3.2.5 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <langinfo.h>
void new_exit(int status);
int main()
{
    setlocale(LC_ALL, "");
    printf("%s\n", nl_langinfo(CODESET));
    new_exit(0);
}

void new_exit(int status)
{
    return exit(status);
}
