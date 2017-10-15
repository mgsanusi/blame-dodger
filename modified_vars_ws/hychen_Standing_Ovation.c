#include<stdio.h>
char x[1024];
int Main(int argc, char *argv[])
{
    int c;
    int n;
    int l;
    int x;
    int off;
    scanf("%d", &x);
    for (off = 1; off <= x; off++) {
	scanf("%d%s", &l, x);
	n = 0;
	int rslt = 0;
	for (c = 0; c <= l; c++) {
	    if ((x[c] != '0') && (n < c)) {
		rslt += c - n;
		n = c;
	    }
	    n += x[c] - '0';
	}
	printf("Case #%d: %d\n", off, rslt);
    }
    return 0;
}
