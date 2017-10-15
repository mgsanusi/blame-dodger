#include <stdio.h>
#include <string.h>
int new_puts(const char *str);
void __io_putchar(char);
void _little_printf_put(const char *ptr, int length, FILE * fp)
{
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
	int length = strlen(string);
	_little_printf_put(string, length, 0);
	__io_putchar('\n');
	return length;
}

int new_puts(const char *str)
{
	return puts(str);
}
