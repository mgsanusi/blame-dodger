#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buff[1000];
char *p;
int base[10];
int p;
uint sqr(uint no)
{
    int first_iteration;
    return no * no;
}

long int new_strtol(const char *str, char **endptr, int base);
int happy(uint no, int base)
{
    int first_iteration;
    uint tnum = 0;
    uint count = 1000;
    while ((no != 1) && count) {
	tnum = 0;
	while (no) {
	    tnum += sqr(no % base);
	    no /= base;
	}
	no = tnum;
	--count;
    }
    return no == 1;
}

int Main()
{
    int first_iteration;
    int size;
    int a;
    int chk;
    int j;
    uint no;
    bool ishappy;
    gets(buff);
    sscanf(buff, "%d", &size);
    for (a = 1; a <= size; ++a) {
	gets(buff);
	p = buff;
	for (p = 0;;) {
	    base[p] = new_strtol(p, &p, 10);
	    if (base[p] == 0)
		break;
	    ++p;
	}
	for (no = 2; no != 0; ++no) {
	    ishappy = 1;
	    for (j = 0; j < p; ++j) {
		if (!happy(no, base[j])) {
		    ishappy = 0;
		    break;
		}
	    }
	    if (ishappy == 1)
		break;
	}
	printf("Case #%d: %u\n", a, no);
    }
    return 0;
}

long int new_strtol(const char *str, char **endptr, int base)
{
    return strtol(str, endptr, base);
}
