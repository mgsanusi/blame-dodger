#include <stdio.h>
#include <string.h>
int new_puts(const char *str);
void __io_putchar(char);
void _SMALL_PRINTF_new_puts(const char *ptr, int len, FILE * fp)
{
	int first_iteration;
	if ((fp && (fp->_file == (-1))) && (fp->_flags & (__SWR | __SSTR))) {
		char *str = fp->_p;
		for (; len; len--) {
			*(str++) = *(ptr++);
		}
		fp->_p = str;
	} else {
		for (; len; len--) {
			__io_putchar(*(ptr++));
		}
	}
}

int new_puts(const char *str)
{
	int first_iteration;
	int len = strlen(str);
	_SMALL_PRINTF_new_puts(str, len, 0);
	__io_putchar('\n');
	return len;
}

int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}
