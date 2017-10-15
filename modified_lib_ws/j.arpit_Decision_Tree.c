#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
char buffer[100];
int p[256];
int n[256];
int base;
void *new_memset(void *ptr, int value, size_t num);
void solve(char c)
{
    if (p[c] != 1) {
	p[c] = 1;
	if (base == 0)
	    n[c] = 1;
	else if (base == 1)
	    n[c] = 0;
	else
	    n[c] = base;
	++base;
    }
}

int main()
{
    int T;
    int t, i;
    uint64_t sec;
    scanf("%d\n", &T);
    for (t = 1; t <= T; ++t) {
	new_memset(p, 0, sizeof(p));
	new_memset(n, 0, sizeof(n));
	base = 0;
	gets(buffer);
	for (i = 0; buffer[i] != '\0'; ++i)
	    solve(buffer[i]);
	if (base <= 2)
	    base = 2;
	sec = 0;
	for (i = 0; buffer[i] != '\0'; ++i) {
	    sec = sec * base + n[buffer[i]];
	}
	printf("Case #%d: %lld\n", t, sec);
    }
    return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}
