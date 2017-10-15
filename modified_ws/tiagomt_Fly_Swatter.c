#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN		16
#define MIN(a,b)	(((a) < (b)) ? (a) : (b))
#define INFINITO	0x3F3F3F3F
int v[2][MAXN];
char mrc[MAXN];
int n;
int r;
void bt(int a, int p)
{
	int i;
	if (p == n) {
		r = MIN(r, a);
		return;
	}
	for (i = 0; i < n; i++) {
		if (mrc[i]) {
			continue;
		}
		mrc[i] = 1;
		bt(a + v[0][p] * v[1][i], p + 1);
		mrc[i] = 0;
	}
}

int main(void)
{
	int nc, h;
	int i, j;
	for (scanf("%d", &nc), h = 1; h <= nc; h++) {
		scanf("%d", &n);
		for (i = 0; i < 2; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &(v[i][j]));
			}
		}
		r = INFINITO;
		memset(mrc, 0, sizeof(mrc));
		bt(0, 0);
		printf("Case #%d: %d\n", h, r);
	}
	return 0;
}
