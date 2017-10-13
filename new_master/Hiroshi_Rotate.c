#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ans[] = {
	"Neither",
	"Red",
	"Blue",
	"Both",
};

char board[50][50];
int N, K;

int check_p(int x, int y)
{
	int k, p;
	int n, m;

	p = board[y][x];

	k = 1;
	n = x + 1;
	while (n < N) {
		if (board[y][n++] == p) {
			if (++k >= K)
				return p;
		} else
			break;
	}

	k = 1;
	n = y + 1;
	while (n < N) {
		if (board[n++][x] == p) {
			if (++k >= K)
				return p;
		} else
			break;
	}

	k = 1;
	n = x + 1;
	m = y + 1;
	while (n < N && m < N) {
		if (board[m++][n++] == p) {
			if (++k >= K)
				return p;
		} else
			break;
	}

	k = 1;
	n = x - 1;
	m = y + 1;
	while (n >= 0 && m < N) {
		if (board[m++][n--] == p) {
			if (++k >= K)
				return p;
		} else
			break;
	}

	return 0;
}

int check(void)
{
	int x, y;
	int a, c;

	a = 0;
	for (y = 0; y < N; y++) {
		for (x = 0; x < N; x++) {
			int p = board[y][x];

			/* goto next line */
			if (p == 0)
				break;

			if (p & a)
				continue;

			c = check_p(x, y);
			a |= c;
		}
	}

	return a;
}

void solve(int x)
{
	char buf[4096];
	int i;
	int y;

	fgets(buf, 4096, stdin);
	sscanf(buf, "%d %d", &N, &K);

	for (i = N - 1; i >= 0; i--) {
		int n, m;

		fgets(buf, 4096, stdin);

		memset(board[i], 0, 50);

		for (n = 0, m = 0; n < N; n++) {
			switch (buf[N - n - 1]) {
			case '.':
				break;
			case 'R':
				board[i][m++] = 1;
				break;
			case 'B':
				board[i][m++] = 2;
				break;
			}
		}
	}

	y = check();
	printf("Case #%d: %s\n", x, ans[y]);
}

int main(int argc, char **argv)
{
	char buf[256];
	int t, T;

	fgets(buf, 256, stdin);
	sscanf(buf, "%d", &T);

	for (t = 1; t <= T; t++)
		solve(t);

	return 0;
}
