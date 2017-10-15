#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buffer[100];
int T;
int new_putchar(int character);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int comp(char *a, char *b)
{
    return (*a - *b);
}

int main()
{
    int t, i, j, k, bl;
    gets(buffer);
    sscanf(buffer, "%d\n", &T);
    for (t = 1; t <= T; ++t) {
	printf("Case #%d: ", t);
	gets(buffer);
	bl = strlen(buffer);
	for (i = bl - 1; i; --i) {
	    if (buffer[i] > buffer[i - 1])
		break;
	}
	if (i != 0) {
	    for (j = 0; j < i - 1; ++j)
		new_putchar(buffer[j]);
	    for (j = bl - 1; buffer[j] <= buffer[i - 1]; --j);
	    new_putchar(buffer[j]);
	    for (k = bl - 1; k > j; --k)
		new_putchar(buffer[k]);
	    new_putchar(buffer[i - 1]);
	    for (k = j - 1; k >= i; --k)
		new_putchar(buffer[k]);
/* 	    for (j = 0 ; j < i - 1 ; ++j) new_putchar(buffer[j]) ; */
/* 	    new_putchar(buffer[bl-1]) ; */
/* 	    for (j = i - 1 ; j < bl - 1 ; ++j) */
/* 	      new_putchar(buffer[j]) ; */
	} else {
	    //      new_qsort(buffer, 1, bl, comp) ;
	    for (j = bl - 1; buffer[j] == '0'; --j);
	    new_putchar(buffer[j]);
	    new_putchar('0');
	    for (k = bl - 1; k > j; --k)
		new_putchar(buffer[k]);
	    for (k = j - 1; k >= 0; --k)
		new_putchar(buffer[k]);
	}
	new_putchar('\n');
    }
    return 0;
}

int new_putchar(int character);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

int new_putchar(int character)
{
    return putchar(character);
}
