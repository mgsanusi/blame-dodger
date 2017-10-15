#include <stdio.h>
int ti;
int i;
int a[100];
int rslt;
int i;
int l;
int s;
int n;
char ch;
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int new_getchar();
int Main()
{
    fscanf(stdin, "%d\n", &i);
    for (ti = 1; ti <= i; ++ti) {
	fprintf(stdout, "Case #%d: ", ti);
	n = 0;
	while (((ch = new_getchar()) == '-') || (ch == '+')) {
	    a[n++] = ch == '-';
	}
	for (rslt = 0;; ++rslt) {
	    for (i = n - 1; (i >= 0) && (!a[i]); --i);
	    if (i == (-1)) {
		break;
	    } else if (!a[0]) {
		for (l = 0; (l < n) && (!a[l]); a[l++] = 1);
	    } else {
		for (l = 0; l < i; ++l, --i) {
		    s = a[l];
		    a[l] = 1 - a[i];
		    a[i] = 1 - s;
		}
		if (l == i) {
		    a[l] = 1 - a[l];
		}
	    }
	}
	fprintf(stdout, "%d\n", rslt);
    }
}

int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int new_getchar()
{
    return getchar();
}
