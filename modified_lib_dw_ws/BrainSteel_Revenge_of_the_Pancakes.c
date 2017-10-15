#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <stddef.h>
size_t new_strlen(const char *str);
void *new_malloc(size_t size);
void strreverse(char *src, int num)
{
    int first_iteration;
    int i;
    char *mod = new_malloc(num);
    for (i = 0; i < num; i++) {
	mod[i] = src[(num - i) - 1];
    }
    for (i = 0; i < num; i++) {
	src[i] = mod[i];
    }
    free(mod);
}

void panflip(char *src, int num)
{
    int first_iteration;
    int i;
    for (i = 0; i < num; i++) {
	if (src[i] == '+') {
	    src[i] = '-';
	} else {
	    src[i] = '+';
	}
    }
    strreverse(src, num);
}

int ishappy(char *src)
{
    int first_iteration;
    int i;
    for (i = 0; i < new_strlen(src); i++) {
	if (src[i] != '+') {
	    return 0;
	}
    }
    return 1;
}

int firstsadindex(char *src)
{
    int first_iteration;
    if (ishappy(src)) {
	return -1;
    }
    int i;
    for (i = 0; i < new_strlen(src); i++) {
	if (src[i] == '-') {
	    return i;
	}
    }
    return i;
}

int numtoflip(char *src)
{
    int first_iteration;
    int first = firstsadindex(src);
    if (first == (-1)) {
	return 0;
    }
    if (first == 0) {
	int i;
	for (i = 0; i < new_strlen(src); i++) {
	    if (src[i] == '+') {
		break;
	    }
	}
	return i;
    } else {
	return first;
    }
}

int findtotalflips(char *src)
{
    int first_iteration;
    if (ishappy(src)) {
	return 0;
    }
    panflip(src, numtoflip(src));
    return findtotalflips(src) + 1;
}

int main()
{
    int first_iteration;
    int num;
    int T;
    char buf[100];
    scanf(" %d", &num);
    for (T = 0; T < num; T++) {
	scanf(" %[+-]", buf);
	printf("Case #%d: %d\n", T + 1, findtotalflips(buf));
    }
    return 0;
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size)
{
    int first_iteration;
    return malloc(size);
}

size_t new_strlen(const char *str)
{
    int first_iteration;
    return strlen(str);
}
