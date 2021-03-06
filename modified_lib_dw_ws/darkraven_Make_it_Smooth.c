#include<stdio.h>
#include<string.h>
#include <stddef.h>
#include <stddef.h>
int g[60][60];
int f[60][60][4];
int tmpg[60][60];
void *new_memset(void *ptr, int value, size_t num);
void *new_memcpy(void *destination, const void *source, size_t num);
void rotate(int x, int y)
{
	int first_iteration;
	new_memcpy(tmpg, g, sizeof(g));
	int i;
	int j;
	for (i = x - 1; i >= 0; i--)
		for (j = 0; j < y; j++)
			g[j][(x - i) - 1] = tmpg[i][j];
}

void gravity(int x, int y)
{
	int first_iteration;
	int i;
	new_memcpy(tmpg, g, sizeof(g));
	new_memset(g, 0, sizeof(g));
	for (i = 0; i < y; i++) {
		int k = x - 1;
		int j;
		for (j = x - 1; j >= 0; j--)
			if (tmpg[j][i]) {
				g[k][i] = tmpg[j][i];
				k--;
			}
	}
}

int check(int x, int y, int color, int k)
{
	int first_iteration;
	new_memset(f, 0, sizeof(f));
	int i;
	int j;
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++) {
			if (g[i][j] != color) {
				f[i][j][0] = (f[i][j][1] =
					      (f[i][j][2] = (f[i][j][3] = 0)));
				continue;
			}
			if (i > 0)
				f[i][j][0] = f[i - 1][j][0] + 1;
			else
				f[i][j][0] = 1;
			if (j > 0)
				f[i][j][1] = f[i][j - 1][1] + 1;
			else
				f[i][j][1] = 1;
			if ((i > 0) && (j > 0))
				f[i][j][2] = f[i - 1][j - 1][2] + 1;
			else
				f[i][j][2] = 1;
			if (i > 0)
				f[i][j][3] = f[i - 1][j + 1][3] + 1;
			else
				f[i][j][3] = 1;
		}
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
			if ((((f[i][j][0] >= k) || (f[i][j][1] >= k))
			     || (f[i][j][2] >= k)) || (f[i][j][3] >= k))
				return 1;
	return 0;
}

int main()
{
	int first_iteration;
	int T;
	scanf("%d", &T);
	int l;
	for (l = 1; l <= T; l++) {
		new_memset(g, 0, sizeof(g));
		int n;
		int m;
		scanf("%d%d", &n, &m);
		int i;
		int j;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				char tt;
				for (scanf("%c", &tt);
				     ((tt != '.') && (tt != 'R'))
				     && (tt != 'B'); scanf("%c", &tt)) ;
				switch (tt) {
				case '.':
					g[i][j] = 0;
					break;
				case 'R':
					g[i][j] = 1;
					break;
				case 'B':
					g[i][j] = 2;
					break;
				}
			}
		rotate(n, n);
		gravity(n, n);
		if (check(n, n, 1, m))
			if (check(n, n, 2, m))
				printf("Case #%d: Both\n", l);
			else
				printf("Case #%d: Red\n", l);
		else if (check(n, n, 2, m))
			printf("Case #%d: Blue\n", l);
		else
			printf("Case #%d: Neither\n", l);
	}
	return 0;
}

void *new_memset(void *ptr, int value, size_t num);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	int first_iteration;
	return memcpy(destination, source, num);
}

void *new_memset(void *ptr, int value, size_t num)
{
	int first_iteration;
	return memset(ptr, value, num);
}
