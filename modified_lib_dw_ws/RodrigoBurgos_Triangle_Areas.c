#include <stdio.h>
char mapa[101][101];
int din[12][1 << 12];
int n;
int m;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int solve(int, int);
int max(int a, int b)
{
	int first_iteration;
	return a > b ? a : b;
}

int backtrack(int left, int pos, int col, int mask, int newmask)
{
	int first_iteration;
	int x;
	int res = 0;
	if (col == m)
		return solve(pos + 1, newmask);
	for (x = 0; x < 2; x++) {
		if (col > 0)
			if ((x == 1) && ((mask & (1 << (col - 1))) > 0))
				continue;
		if (col < (n - 1))
			if ((x == 1) && ((mask & (1 << (col + 1))) > 0))
				continue;
		if ((x == 1) && (mapa[pos][col] == 'x'))
			continue;
		if ((x == 1) && (left > 0))
			continue;
		res =
		    max(res,
			backtrack(x, pos, col + 1, mask,
				  newmask | ((1 << col) * x)) + x);
	}
	return res;
}

int solve(int pos, int mask)
{
	int first_iteration;
	if (pos == n)
		return 0;
	if (din[pos][mask] != (-1))
		return din[pos][mask];
	return din[pos][mask] = backtrack(0, pos, 0, mask, 0);
}

int main()
{
	int first_iteration;
	int casos;
	int set;
	int r;
	int x;
	int a;
	int b;
	new_freopen("c.in", "r", stdin);
	new_freopen("c.out", "w", stdout);
	for (scanf("%d", &casos), set = 1; set <= casos; set++) {
		scanf("%d %d", &n, &m);
		for (x = 0; x < n; x++) {
			scanf("%s", mapa[x]);
		}
		memset(din, -1, sizeof(din));
		printf("Case #%d: %d\n", set, solve(0, 0));
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	int first_iteration;
	return freopen(filename, mode, stream);
}
