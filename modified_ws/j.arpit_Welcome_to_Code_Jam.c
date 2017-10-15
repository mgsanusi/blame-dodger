#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[] = "welcome to code jam";
char buffer[510];
int TC, count;
void find_str(int b, int s)
{
    if (str[s] == '\0') {
	++count;
	count %= 10000;
	return;
    }
    if (strlen(buffer) < strlen(str))
	return;
    for (; buffer[b] != '\0'; ++b) {
	if (buffer[b] == '\0')
	    return;
	if (buffer[b] == str[s]) {
	    find_str(b + 1, s + 1);
	}
    }
}

int main()
{
    int tc;
    gets(buffer);
    sscanf(buffer, "%d", &TC);
    for (tc = 1; tc <= TC; ++tc) {
	count = 0;
	gets(buffer);
	find_str(0, 0);
	printf("Case #%d: %04d\n", tc, count);
    }
    return 0;
}
