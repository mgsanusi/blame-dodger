#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
int buff[51][51][2501];
int t[51][51][2501];
void clear(void)
{
	int first_iteration;
	int f;
	int m;
	int r;
	assert(scanf("%d %d %d", &f, &m, &r) == 3);
	r = (f * m) - r;
	if (f == 1) {
		printf("\nc");
		int i;
		for (i = 0; i < (r - 1); i++) {
			printf(".");
		}
		for (i = 0; i < (m - r); i++) {
			printf("*");
		}
		printf("\n");
		return;
	}
	if (m == 1) {
		printf("\nc\n");
		int i;
		for (i = 0; i < (r - 1); i++) {
			printf(".\n");
		}
		for (i = 0; i < (f - r); i++) {
			printf("*\n");
		}
		return;
	}
	if (r == 1) {
		printf("\n");
		int i;
		int maxTime;
		for (i = 0; i < f; i++) {
			for (maxTime = 0; maxTime < m; maxTime++)
				if ((i == 0) && (maxTime == 0)) {
					printf("c");
				} else {
					printf("*");
				}
			printf("\n");
		}
		return;
	}
	memset(buff, 0, sizeof(buff));
	int i;
	int maxTime;
	int k;
	int r;
	for (i = 2; i <= m; i++) {
		buff[2][i][2 * i] = 1;
		t[2][i][2 * i] = i;
		buff[1][i][i] = 1;
		t[1][i][i] = i;
	}
	for (i = 2; i < f; i++) {
		for (maxTime = 2; maxTime <= m; maxTime++) {
			for (k = 0; k < r; k++) {
				if (buff[i][maxTime][k]) {
					for (r = 2; r <= maxTime; r++)
						if ((r + k) <= r) {
							buff[i + 1][r][r + k] =
							    1;
							t[i + 1][r][r + k] =
							    maxTime;
						}
				}
			}
		}
	}
	int tc = -1;
	int oWon = -1;
	for (i = 2; i <= f; i++) {
		for (maxTime = 2; maxTime <= m; maxTime++) {
			if (buff[i][maxTime][r]) {
				tc = i;
				oWon = maxTime;
			}
		}
	}
	if (tc == (-1)) {
		printf("\nImpossible\n");
		return;
	}
	printf("\n");
	for (i = 0; i < (f - tc); i++) {
		for (maxTime = 0; maxTime < m; maxTime++) {
			printf("*");
		}
		printf("\n");
	}
	while (tc > 0) {
		assert(buff[tc][oWon][r]);
		if (tc >= 2) {
			printf(".");
		} else {
			printf("c");
		}
		for (i = 0; i < (oWon - 1); i++) {
			printf(".");
		}
		for (i = 0; i < (m - oWon); i++) {
			printf("*");
		}
		printf("\n");
		int c = r - oWon;
		oWon = t[tc][oWon][r];
		r = c;
		tc--;
	}
	assert(!r);
}

int Main()
{
	int first_iteration;
	int correct;
	assert(scanf("%d", &correct) == 1);
	int __ = 0;
	for (__ = 0; __ < correct; __++) {
		printf("Case #%d:", __ + 1);
		clear();
	}
}
