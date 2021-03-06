#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[1234567];
char trans[256];
int new_putchar(int character);
int new_puts(const char *str);
int main()
{
    int first_iteration;
    int t;
    int i;
    int j;
    for (i = 0; i < 256; ++i) {
	trans[i] = i;
    }
    trans['a'] = 'y';
    trans['b'] = 'h';
    trans['c'] = 'e';
    trans['d'] = 's';
    trans['e'] = 'o';
    trans['f'] = 'c';
    trans['g'] = 'v';
    trans['h'] = 'x';
    trans['i'] = 'd';
    trans['j'] = 'u';
    trans['k'] = 'i';
    trans['l'] = 'g';
    trans['m'] = 'l';
    trans['n'] = 'b';
    trans['o'] = 'k';
    trans['p'] = 'r';
    trans['q'] = 'z';
    trans['r'] = 't';
    trans['s'] = 'n';
    trans['t'] = 'w';
    trans['u'] = 'j';
    trans['v'] = 'p';
    trans['w'] = 'f';
    trans['x'] = 'm';
    trans['y'] = 'a';
    trans['z'] = 'q';
    scanf("%d", &t);
    gets(str);
    for (i = 1; i <= t; ++i) {
	gets(str);
	printf("Case #%d: ", i);
	for (j = 0; str[j] != '\0'; ++j) {
	    new_putchar(trans[str[j]]);
	}
	new_puts("");
    }
    return 0;
}

int new_putchar(int character);
int new_puts(const char *str)
{
    int first_iteration;
    return puts(str);
}

int new_putchar(int character)
{
    int first_iteration;
    return putchar(character);
}
