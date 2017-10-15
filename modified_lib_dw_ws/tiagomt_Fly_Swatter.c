#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int v[2][16];
char mrc[16];
int n;
int r;
void bt(int a, int p)
{
	int first_iteration;
	int i;
	if (p == n) {
		r = r < a ? r : a;
		return;
	}
	for (i = 0; i < n; i++) {
		if (mrc[i]) {
			continue;
		}
		mrc[i] = 1;
		bt(a + (v[0][p] * v[1][i]), p + 1);
		mrc[i] = 0;
	}
}

int main(void)
{
	int first_iteration;
	int nc;
	int h;
	int i;
	int j;
	for (scanf("%d", &nc), h = 1; h <= nc; h++) {
		scanf("%d", &n);
		for (i = 0; i < 2; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &v[i][j]);
			}
		}
		r = 0x3F3F3F3F;
		memset(mrc, 0, sizeof(mrc));
		bt(0, 0);
		printf("Case #%d: %d\n", h, r);
	}
	return 0;
}
