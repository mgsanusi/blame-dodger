#include <stdio.h>
#include <string.h>

char grid[50][50];
int used[50][50], r, c, m;

int dfs(int skipR, int skipC, int nowM) {
	int i, j;

	if (used[skipR][skipC])
		return 0;
	used[skipR][skipC] = 1;

	if (r - skipR == 1 || c - skipC == 1)
		return 0;

	if (nowM <= (r - skipR - 2) * (c - skipC - 2) || (nowM - (r - skipR - 2) * (c - skipC - 2)) % 2 == 0) {
		for (i = 0; i < skipR; i++)
			for (j = 0; j < c; j++)
				grid[i][j] = '*';
		for (i = skipR; i < r; i++)
			for (j = 0; j < skipC; j++)
				grid[i][j] = '*';

		for (i = skipR; i < r - 2; i++)
			for (j = skipC; (i - skipR) * (c - skipC - 2) + j - skipC < nowM && j < c - 2; j++)
				grid[i][j] = '*';
		if (nowM - (r - skipR - 2) * (c - skipC - 2) > 0)
			for (i = skipR; (r - skipR - 2) * (c - skipC - 2) + (i - skipR) * 2 < nowM && i < r - 2; i++)
				grid[i][c - 2] = grid[i][c - 1] = '*';
		if (nowM - (r - skipR - 2) * (c - skipC - 2) - (r - skipR - 2) * 2 > 0)
			for (j = skipC; (r - skipR - 2) * (c - skipC - 2) + (r - skipR - 2) * 2 + (j - skipC) * 2 < nowM && j < c - 2; j++)
				grid[r - 2][j] = grid[r - 1][j] = '*';

		return 1;
	}

	if (nowM - c + skipC >= 0 && dfs(skipR + 1, skipC, nowM - c + skipC) || nowM - r + skipR >= 0 && dfs(skipR, skipC + 1, nowM - r + skipR))
		return 1;

	return 0;
}

int main(void) {
	int i, j, k;
	int t;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		int ok;

		scanf("%d %d %d", &r, &c, &m);

		memset(grid, '.', sizeof grid);
		memset(used, 0, sizeof used);

		if (r == 1 || c == 1) {
			ok = 1;
			if (r > 1)
				for (j = 0; j < m; j++)
					grid[j][0] = '*';
			else
				for (j = 0; j < m; j++)
					grid[0][j] = '*';
		} else
			if (m == r * c - 3 || m == r * c - 2)
				ok = 0;
			else if (m == r * c - 1) {
				ok = 1;
				for (j = 0; j < r; j++)
					for (k = 0; k < c; k++)
						grid[j][k] = '*';
			} else if (dfs(0, 0, m))
				ok = 1;
			else
				ok = 0;
		grid[r - 1][c - 1] = 'c';

		printf("Case #%d:\n", i, r, c, m);
		if (ok)
			for (j = 0; j < r; j++) {
				for (k = 0; k < c; k++)
					putchar(grid[j][k]);
				putchar('\n');
			}
		else
			puts("Impossible");
	}

	return 0;
}
