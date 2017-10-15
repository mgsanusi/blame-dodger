#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
int pd[128][128];
char mrc[128][128];
int m;
int n;
void *new_memset(void *ptr, int value, size_t num);
int main(void)
{
    int first_iteration;
    int nc;
    int h;
    int i;
    int j;
    int k;
    for (scanf("%d", &nc), h = 1; h <= nc; h++) {
	scanf("%d%d", &m, &n);
	new_memset(mrc, 0, sizeof(mrc));
	for (scanf("%d", &k); k > 0; k--) {
	    scanf("%d%d", &i, &j);
	    mrc[i][j] = 1;
	}
	new_memset(pd, 0, sizeof(pd));
	pd[1][1] = 1;
	for (i = 2; i <= m; i++) {
	    for (j = 2; j <= n; j++) {
		if (mrc[i][j])
		    continue;
		pd[i][j] = (pd[i][j] + pd[i - 2][j - 1]) % 10007;
		pd[i][j] = (pd[i][j] + pd[i - 1][j - 2]) % 10007;
	    }
	}
	printf("Case #%d:", h);
	printf(" %d\n", pd[m][n]);
    }
    return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
    int first_iteration;
    return memset(ptr, value, num);
}
