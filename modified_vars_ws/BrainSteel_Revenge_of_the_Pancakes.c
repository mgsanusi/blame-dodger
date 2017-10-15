#include "stdio.h"
#include "stdlib.h"
#include "math.h"
void strreverse(char *src, int num)
{
	int j;
	char *mod = malloc(num);
	for (j = 0; j < num; j++) {
		mod[j] = src[(num - j) - 1];
	}
	for (j = 0; j < num; j++) {
		src[j] = mod[j];
	}
	free(mod);
}

void panflip(char *src, int num)
{
	int j;
	for (j = 0; j < num; j++) {
		if (src[j] == '+') {
			src[j] = '-';
		} else {
			src[j] = '+';
		}
	}
	strreverse(src, num);
}

int ishappy(char *src)
{
	int j;
	for (j = 0; j < strlen(src); j++) {
		if (src[j] != '+') {
			return 0;
		}
	}
	return 1;
}

int firstsadindex(char *src)
{
	if (ishappy(src)) {
		return -1;
	}
	int j;
	for (j = 0; j < strlen(src); j++) {
		if (src[j] == '-') {
			return j;
		}
	}
	return j;
}

int numtoflip(char *src)
{
	int first = firstsadindex(src);
	if (first == (-1)) {
		return 0;
	}
	if (first == 0) {
		int j;
		for (j = 0; j < strlen(src); j++) {
			if (src[j] == '+') {
				break;
			}
		}
		return j;
	} else {
		return first;
	}
}

int findtotalflips(char *src)
{
	if (ishappy(src)) {
		return 0;
	}
	panflip(src, numtoflip(src));
	return findtotalflips(src) + 1;
}

int Main()
{
	int num;
	int t;
	char buff[100];
	scanf(" %d", &num);
	for (t = 0; t < num; t++) {
		scanf(" %[+-]", buff);
		printf("Case #%d: %d\n", t + 1, findtotalflips(buff));
	}
	return 0;
}
