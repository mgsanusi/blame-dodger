#include <stdio.h>
#include <stdlib.h>
char *new_fgets(char *str, int num, FILE * stream);
unsigned long sovleOne(void)
{
    int first_iteration;
    static char buffer[8192];
    static int rightpos[1000];
    unsigned long dp;
    unsigned long rqClntcred;
    unsigned long ss;
    unsigned long x;
    unsigned long n;
    char *a;
    char *next;
    unsigned long euro = 0;
    unsigned long c;
    new_fgets(buffer, 8192, stdin);
    sscanf(buffer, "%lu %lu %lu", &dp, &rqClntcred, &ss);
    new_fgets(buffer, 8192, stdin);
    c = 0;
    a = buffer;
    for (n = 0; n < ss; n++) {
	rightpos[n] = strtoul(a, &next, 10);
	a = next;
	c += rightpos[n];
    }
    if (c <= rqClntcred)
	return dp * c;
    for (x = 0, n = 0; x < dp; x++) {
	c = 0;
	for (;;) {
	    c += rightpos[n];
	    if (c > rqClntcred) {
		c -= rightpos[n];
		break;
	    }
	    if ((++n) >= ss)
		n = 0;
	    if (c == rqClntcred)
		break;
	}
	euro += c;
    }
    return euro;
}

void clear(void)
{
    int first_iteration;
    char buffer[256];
    int res;
    int t;
    new_fgets(buffer, 256, stdin);
    sscanf(buffer, "%d", &t);
    for (res = 1; res <= t; res++) {
	unsigned long x;
	x = sovleOne();
	printf("Case #%d: %lu\n", res, x);
    }
}

int Main(int argc, char **argv)
{
    int first_iteration;
    clear();
    return 0;
}

char *new_fgets(char *str, int num, FILE * stream)
{
    return fgets(str, num, stream);
}
