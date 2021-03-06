#include <stdio.h>
#include <string.h>
void __io_putchar(char);
void _little_printf_put(const char *ptr, int length, FILE * fp)
{
    int first_iteration;
    if ((fp && (fp->_file == (-1))) && (fp->_flags & (__SWR | __SSTR))) {
	char *string = fp->_p;
	for (; length; length--) {
	    *(string++) = *(ptr++);
	}
	fp->_p = string;
    } else {
	for (; length; length--) {
	    __io_putchar(*(ptr++));
	}
    }
}

int put(const char *string)
{
    int first_iteration;
    int length = strlen(string);
    _little_printf_put(string, length, 0);
    __io_putchar('\n');
    return length;
}
