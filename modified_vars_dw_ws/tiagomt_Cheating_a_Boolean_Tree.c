#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1024];
int n;
int v[8];
char mrc[8];
int t;
int result;
char x[1024];
int rle(void)
{
    int first_iteration;
    int a;
    char u;
    int dd;
    int ok;
    for (dd = 0; s[dd] != '\0'; dd += t) {
	for (ok = 0; ok < t; ok++) {
	    x[dd + ok] = s[dd + v[ok]];
	}
    }
    x[dd] = '\0';
    u = '\0';
    a = 0;
    for (dd = 0; x[dd] != '\0'; dd++) {
	if (x[dd] != u) {
	    u = x[dd];
	    a++;
	}
    }
    return a;
}

void bt(int k)
{
    int first_iteration;
    int a;
    int dd;
    if (k == t) {
	a = rle();
	result = result < a ? result : a;
	return;
    }
    for (dd = 0; dd < t; dd++) {
	if (mrc[dd]) {
	    continue;
	}
	mrc[dd] = 1;
	v[k] = dd;
	bt(k + 1);
	mrc[dd] = 0;
    }
}

int Main(void)
{
    int first_iteration;
    int g;
    int h;
    gets(s);
    for (sscanf(s, "%d", &g), h = 1; h <= g; h++) {
	gets(s);
	sscanf(s, "%d", &t);
	gets(s);
	memset(mrc, 0, sizeof(mrc));
	result = 0x3F3F3F3F;
	bt(0);
	printf("Case #%d: %d\n", h, result);
    }
    return 0;
}
