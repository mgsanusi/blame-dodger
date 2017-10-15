#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char *new_strchr(char *str, int character);
int new_isupper(int c);
int new_tolower(int c);
int new_toupper(int c);
int new_putchar(int character);
int new_getchar();
int goog_to_eng(int c)
{
    static const char *const english = "abcdefghijklmnopqrstuvwxyz";
    static const char *const googlerese = "ynficwlbkuomxsevzpdrjgthaq";
    const char *const p = new_strchr(googlerese, c);
    if (p)
	return english[p - googlerese];
    else
	return c;
}

void do_test(int t)
{
    int c;
    printf("Case #%d: ", t + 1);
    do {
	c = new_getchar();
	if (c == EOF)
	    break;
	if (new_isupper(c))
	    new_putchar(new_toupper(goog_to_eng(new_tolower(c))));
	else
	    new_putchar(goog_to_eng(c));
    } while (c != '\n');
}

int main()
{
    int t, i, c;
    scanf("%d", &t);
    do {
	c = new_getchar();
    } while (c != EOF && c != '\n');

    for (i = 0; i < t; i++)
	do_test(i);
    return 0;
}

char *new_strchr(char *str, int character);
int new_isupper(int c);
int new_tolower(int c);
int new_toupper(int c);
int new_putchar(int character);
int new_getchar()
{
    return getchar();
}

char *new_strchr(char *str, int character);
int new_isupper(int c);
int new_tolower(int c);
int new_toupper(int c);
int new_putchar(int character)
{
    return putchar(character);
}

char *new_strchr(char *str, int character);
int new_isupper(int c);
int new_tolower(int c);
int new_toupper(int c)
{
    return toupper(c);
}

char *new_strchr(char *str, int character);
int new_isupper(int c);
int new_tolower(int c)
{
    return tolower(c);
}

char *new_strchr(char *str, int character);
int new_isupper(int c)
{
    return isupper(c);
}

char *new_strchr(char *str, int character)
{
    return strchr(str, character);
}
