#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN		128
#define MAXQ		1024
#define MAXS		128
#define INFINITO	0x33333333
#define MIN(a,b)	(((a) < (b)) ? (a) : (b))
char se[MAXN][MAXS];
int n;
char m[MAXQ][MAXN];
int q;
int b[MAXQ][MAXN];
int main(void)
{
    char s[MAXS];
    int nc, h;
    int res;
    int i, j, k;
    gets(s);
    for (sscanf(s, "%d", &nc), h = 1; h <= nc; h++) {
	gets(s);
	sscanf(s, "%d", &n);
	for (i = 0; i < n; i++) {
	    gets(se[i]);
	}
	memset(m, 0, sizeof(m));
	gets(s);
	sscanf(s, "%d", &q);
	for (i = 1; i <= q; i++) {
	    gets(s);
	    for (j = 0; j < n; j++) {
		if (strcmp(s, se[j]) == 0) {
		    break;
		}
	    }
	    if (j < n) {
		m[i][j] = 1;
	    }
	}
	for (j = 0; j < n; j++) {
	    b[0][j] = 0;
	}
	for (i = 1; i <= q; i++) {
	    for (j = 0; j < n; j++) {
		b[i][j] = INFINITO;
		if (m[i][j]) {
		    continue;
		}
		for (k = 0; k < n; k++) {
		    b[i][j] = MIN(b[i][j], b[i - 1][k] + 1);
		}
		b[i][j] = MIN(b[i][j], b[i - 1][j]);
	    }
	}
	res = INFINITO;
	for (j = 0; j < n; j++) {
	    if (b[q][j] < res) {
		res = b[q][j];
	    }
	}
	printf("Case #%d: %d\n", h, res);
    }
    return 0;
}
