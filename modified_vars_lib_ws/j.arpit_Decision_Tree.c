#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
char buf[100];
int p[256];
int n[256];
int base;
void *new_memset(void *ptr, int value, size_t num);
void clear(char x)
{
	if (p[x] != 1) {
		p[x] = 1;
		if (base == 0)
			n[x] = 1;
		else if (base == 1)
			n[x] = 0;
		else
			n[x] = base;
		++base;
	}
}

int Main()
{
	int second;
	int d;
	int i;
	uint64_t sec;
	scanf("%d\n", &second);
	for (d = 1; d <= second; ++d) {
		new_memset(p, 0, sizeof(p));
		new_memset(n, 0, sizeof(n));
		base = 0;
		gets(buf);
		for (i = 0; buf[i] != '\0'; ++i)
			clear(buf[i]);
		if (base <= 2)
			base = 2;
		sec = 0;
		for (i = 0; buf[i] != '\0'; ++i) {
			sec = (sec * base) + n[buf[i]];
		}
		printf("Case #%d: %lld\n", d, sec);
	}
	return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}
